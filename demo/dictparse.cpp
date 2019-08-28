/*
 * @File_name: dictparse.cpp
 * @Description: 
 * @Author: liuyuan21@baidu.com
 * @Date: 2019-08-13 16:26:33
 * @LastEditTime: 2019-08-28 11:33:36
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include "dict_handle.h"
#include "user_defined_type.h"

const size_t COLUMN_0 = 0;
const size_t COLUMN_1 = 1;
const size_t COLUMN_2 = 2;
const size_t COLUMN_3 = 3;
const size_t COLUMN_4 = 4;
const size_t COLUMN_5 = 5;

int main(int argc, char* argv[]){
    std::string optstring = "f:h";
    std::string dict_name;
    char optch = '\0';
    while ((optch = getopt(argc, argv, optstring.c_str())) != -1) {
        switch (optch){
            case 'f':
                dict_name = optarg;
            break;
            case 'h':
                std::cout << "usage: ./dictparse -f dict_file" << std::endl;
                exit(EXIT_SUCCESS);
            default:
                std::cout << "usage: ./dictparse -f dict_file" << std::endl;
                exit(EXIT_SUCCESS);
        }
    }
    if (dict_name.empty()) {
        std::cout << "usage: ./dictparse -f dict_file" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ifstream finput_file(dict_name.c_str());
    std::string line;
    dp::ErrorCode ret_code = dp::OK;
    dp::DictHandle dict_handle;

    dp::ParseUserType<dp::UserTypeExample>::Func func = \
        boost::bind(&dp::parse_usertype_function, _1, _2);
    dp::ParseUserType<dp::UserTypeExample> user_type;
    user_type.set_func_map(func);

    while (std::getline(finput_file, line)) {
        dict_handle.split_line_columns(line, "\t");
        std::vector<std::string> columns = dict_handle.get_columns();

        int int_value = 0;
        ret_code = dict_handle.get_value<int>(COLUMN_0, &int_value);
        std::cout << int_value << " ";
        if (ret_code != dp::OK) {
            continue;
        }

        char char_value = 0;
        ret_code = dict_handle.get_value<char>(COLUMN_1, &char_value);
        std::cout << char_value << " ";
        if (ret_code != dp::OK) {
            continue;
        }

        double double_value = 0.0;
        ret_code = dict_handle.get_value<double>(COLUMN_2, &double_value);
        std::cout << double_value << " ";
        if (ret_code != dp::OK) {
            continue;
        }

        char* str_value = NULL;
        ret_code = dict_handle.get_value<char*>(COLUMN_3, &str_value);
        std::cout << "\"" << str_value << "\"" << " ";
        if (ret_code != dp::OK) {
            continue;
        }

        char *arr_value = NULL;
        size_t count = 0;
        ret_code = dict_handle.get_value<char>(COLUMN_4, &arr_value, &count);
        if (ret_code != dp::OK) {
            continue;
        }
        if (arr_value != NULL && count != 0) {
            std::cout << "[";
            for (size_t i = 0; i < count; ++i) {
                std::cout << arr_value[i] << ",";
            }
            std::cout << "] ";
            free(arr_value);
        }

        dp::UserTypeExample user_type_value;
        ret_code = dict_handle.get_user_defined_value \
            <dp::UserTypeExample>(COLUMN_5, &user_type_value);
        if (ret_code != dp::OK) {
            continue;
        }
        std::cout << "{";
        std::cout << user_type_value.int_value << ",";
        std::cout << user_type_value.double_value << ",";
        std::cout << user_type_value.char_value << ",";
        std::cout << "}" << std::endl;

	
    }

	
}
