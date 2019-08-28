/*
 * @File_name: 
 * @Description: 
 * @Author: liuyuan21@baidu.com
 * @Date: 2019-08-13 16:26:33
 * @LastEditTime: 2019-08-28 11:32:13
 */
#ifndef GOODCODER_PARSE_COMM_TYPE_H
#define GOODCODER_PARSE_COMM_TYPE_H
#include <string>
#include <sstream>
#include <vector>
#include "util.h"
namespace dp{
    template <typename T> 
    class ParseCommType{
        public :
        void parse_str_defined_type(const std::string str, T* result);
        void parse_str_defined_type(const std::string str, T** result, size_t* count);
    };

    /**
     * @brief 解析内置类型
     * @param string
     * @param T*
     * @return void
     */
    template <typename T>
    void ParseCommType<T>::parse_str_defined_type(const std::string str, T* result){
        std::stringstream stream;
        stream << str;
        stream >> *result;
    }

    /**
     * @brief 解析内置类型bulid-in T[num]
     * @param string
     * @param T**
     * @param size_t*
     * @return void
     */
    template <typename T>
    void ParseCommType<T>::parse_str_defined_type(const std::string str, T** result, size_t* count){
        std::vector<T> vec;
        Util::split_string<T>(str, ",", &vec);
        *count = vec.size();
        T* result_tmp = new T[*count];
        //换成智能指针？
        std::copy(vec.begin(), vec.end(), result_tmp);
        *result = result_tmp;
    }
}
#endif
//GOODCODER_PARSE_COMM_TYPE_H