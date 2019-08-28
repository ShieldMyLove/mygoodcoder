/*
 * @File_name: dict_handle.h
 * @Description: 
 * @Author: liuyuan21@baidu.com
 * @Date: 2019-08-28 10:28:09
 * @LastEditTime: 2019-08-28 11:34:16
 */
#ifndef GOODCODER_DICT_HANDLE_H
#define GOODCODER_DICT_HANDLE_H
#include <vector>
#include <string>

#include <boost/algorithm/string/classification.hpp>  
#include <boost/algorithm/string/split.hpp>  
#include <boost/type_traits.hpp>
#include "util.h"
#include "parse_comm_type.h"
#include "parse_user_type.h"
namespace dp{
    class DictHandle{
        public:
        DictHandle();
        ~DictHandle();
        void split_line_columns(const std::string line, const std::string pattern);
            const std::vector<std::string> get_columns();
            //const 的意义？
            template <typename T>
            ErrorCode get_value(const size_t index, T* value); 
            template <typename T>
            ErrorCode get_value(const size_t index, T** value, size_t* count);
            template <typename T>
            ErrorCode get_user_defined_value(const size_t index, T* value);
        private:
            std::vector<std::string> _columns;

    };

    /**
     * @brief 处理通用类型，获取类型值
     * @param size_t 第几列
     * @param T* 类型值指针
     * @return ErrorCode 错误码
     */
    template <typename T>
    ErrorCode DictHandle::get_value(const size_t index, T* value){
        std::vector<std::string> columns = get_columns();
        size_t len = columns.size(); 
        if (index >= len) {
            return OVER_MAX_LEN;
        }
        std::string column = columns[index];
        if (column.empty()){
            return EMPTY_STR; 
        }
        /*bool user_type = boost::is_class<T>::value;
        if(user_type == true){
            ParseUserType<T> parse_user_type;
            parse_user_type.parse_str_defined_type(column,value);
        }*/
        ParseCommType<T> *parse_comm = new ParseCommType<T>();
        parse_comm->parse_str_defined_type(column, value);	
        free(parse_comm);
        return OK;
    }

    /**
     * @brief 处理通用类型build-in T[num]，获取类型值
     * @param size_t 第几列
     * @param T** 类型值指针
     * @param size_t* num个数
     * @return ErrorCode 错误码
     */
    template <typename T>
    ErrorCode DictHandle::get_value(const size_t index, T** value, size_t* count){
        std::vector<std::string> columns = get_columns();
        size_t len = columns.size(); 
        if (index >= len){
            return OVER_MAX_LEN;
        }
        std::string column = columns[index];
        if (column.empty()) {
            return EMPTY_STR; 
        }
        ParseCommType<T> *parse_comm = new ParseCommType<T>();
        parse_comm->parse_str_defined_type(column, value, count);	
        free(parse_comm);
        return OK;
    }

    /**
     * @brief 处理用户指定类型，获取类型值
     * @param size_t 第几列
     * @param T* 类型值指针
     * @return ErrorCode 错误码
     */
    template <typename T>
    ErrorCode DictHandle::get_user_defined_value(const size_t index, T* value){
        std::vector<std::string> columns = get_columns();
        size_t len = columns.size(); 
        if (index >= len) {
            return OVER_MAX_LEN;
        }
        std::string column = columns[index];
        if (column.empty()) {
            return EMPTY_STR; 
        }
        ParseUserType<T> *parse_user_type = new ParseUserType<T>();
        parse_user_type->parse_str_defined_type(column, value);
        free(parse_user_type);

        return OK;
    }

    /**
     * @brief 函数模板特化,不是inline可以在cpp中定义
     * @param size_t 第几列
     * @param char** 字符值指针
     * @return ErrorCode 错误码
     */
    template <>
    ErrorCode DictHandle::get_value<char*>(const size_t index, char** value);

}
#endif 
//GOODCODER_DICT_HANDLE_H