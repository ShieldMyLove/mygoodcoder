/*
 * @File_name: utin.h
 * @Description: 
 * @Author: liuyuan21@baidu.com
 * @Date: 2019-08-28 10:53:16
 * @LastEditTime: 2019-08-28 11:30:17
 */

#ifndef GOODCODER_UTIL_H
#define GOODCODER_UTIL_H
#include <string>
#include <vector>
#include <sstream>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

namespace dp{

    enum ErrorCode{
        OK,
        EMPTY_STR,
        OVER_MAX_LEN,
        TYPEMAP_NOT_FOUND
    };
    class Util{
        public:
            template <typename T>
            static void split_string(const std::string str, const std::string separator, \
                    std::vector<T>* ret_vec);
    };
    /**
     * @brief 分割字符串并添加到指定类型的vector中 
     * @param string 被分割字符串
     * @param string 分割符
     * @param vector 存放容器
     * @return void
     */

    template <typename T>
    void Util::split_string(const std::string str, const std::string separator, \
            std::vector<T>* ret_vec){
        if (str.empty() || ret_vec == NULL) {
            return;
        }
        std::vector<std::string> tmp_vec;
        boost::split(tmp_vec, str, boost::is_any_of(separator));
        for (std::vector<std::string>::iterator it = tmp_vec.begin(); it != tmp_vec.end(); ++it) {
            //换成auto?
            T tmp_value;	
            std::stringstream stream;
            stream << *it;
            stream >> tmp_value;
            ret_vec->push_back(tmp_value);
            //用cast代替？
        }
    }
}

#endif
//GOODCODER_UTIL_H
