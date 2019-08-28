/*
 * @File_name: 
 * @Description: 
 * @Author: liuyuan21@baidu.com
 * @Date: 2019-08-13 16:26:33
 * @LastEditTime: 2019-08-28 11:30:34
 */

#ifndef GOODCODER_USER_DEFINED_TYPE_H
#define GOODCODER_USER_DEFINED_TYPE_H

#include <string>
#include <vector>
#include "parse_comm_type.h"
namespace dp{

    struct UserTypeExample 
    {
        int int_value;
        double double_value;
        char char_value;
    };
    /**
     * @brief 用户自定义函数
     * @param string 
     * @param UserTypeExample
     * @return void
     */
    void parse_usertype_function(const std::string str, UserTypeExample* user_type){
        std::vector<std::string> user_data;  
        Util::split_string(str, "|", &user_data);

        ParseCommType<int> *parse_comm_int = new ParseCommType<int>();	
        parse_comm_int->parse_str_defined_type(user_data[0], &user_type->int_value);

        ParseCommType<double> *parse_comm_double = new ParseCommType<double>();	
        parse_comm_double->parse_str_defined_type(user_data[1], &user_type->double_value);

        ParseCommType<char> *parse_comm_char = new ParseCommType<char>();	
        parse_comm_char->parse_str_defined_type(user_data[2], &user_type->char_value);

        free(parse_comm_int);
        free(parse_comm_double);
        free(parse_comm_char);
    }
}
#endif
//GOODCODER_USER_DEFINED_TYPE_H