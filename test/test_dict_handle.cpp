/*
 * @File_name: test_dict_handle.cpp
 * @Description: 
 * @Author: liuyuan21@baidu.com
 * @Date: 2019-08-27 17:14:02
 * @LastEditTime: 2019-08-28 11:36:02
 */
#include "dict_handle.h"
#include <gtest/gtest.h>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "user_defined_type.h"
	
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/**
 * @brief 
**/
class TestDictHandleDictHandleSuite : public ::testing::Test{
    protected:
        TestDictHandleDictHandleSuite(){};
        virtual ~TestDictHandleDictHandleSuite(){};
        virtual void SetUp() {
            //Called befor every TEST_F(test_DictHandle_DictHandle_suite, *)
            _test_dict_handle = new dp::DictHandle;
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_DictHandle_DictHandle_suite, *)
            delete _test_dict_handle;
        };
        dp::DictHandle *_test_dict_handle;
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestDictHandleDictHandleSuite, case_name1)
{
    _test_dict_handle->split_line_columns("1\ta\t3.14", "\t");
    ASSERT_EQ(3, (int)_test_dict_handle->get_columns().size());
}
 
/**
 * @brief 
**/
class TestDictHandleSplitLineColumnsSuite : public ::testing::Test{
    protected:
        TestDictHandleSplitLineColumnsSuite(){};
        virtual ~TestDictHandleSplitLineColumnsSuite(){};
        virtual void SetUp() {
            //Called befor every TEST_F(test_DictHandle_split_line_columns_suite, *)
            _test_dict_handle = new dp::DictHandle;
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_DictHandle_split_line_columns_suite, *)
            delete _test_dict_handle;
        };
        dp::DictHandle *_test_dict_handle;
};
 
/**
 * @brief z
 * @begin_version 
**/
TEST_F(TestDictHandleSplitLineColumnsSuite, case_name1)
{
    _test_dict_handle->split_line_columns("1\ta\t3.14", "\t");
    const std::vector<std::string> test_vec_str = _test_dict_handle->get_columns();
    ASSERT_STREQ("1", test_vec_str[0].c_str());
}
 
/**
 * @brief 
**/
class TestDictHandleGetValueSuite : public ::testing::Test{
    protected:
        TestDictHandleGetValueSuite(){};
        virtual ~TestDictHandleGetValueSuite(){};
        virtual void SetUp() {
            _test_dict_handle = new dp::DictHandle;
            _test_dict_handle->split_line_columns("1\tb\t3.14\tteststring\ta,b,c,d", "\t");
        };
        virtual void TearDown() {
            delete _test_dict_handle;
        };
        dp::DictHandle *_test_dict_handle;
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestDictHandleGetValueSuite, case_name1)
{
    int int_value;
    dp::ErrorCode ret_code = _test_dict_handle->get_value<int>(0, &int_value);
    ASSERT_EQ(1, int_value);
    ASSERT_EQ(dp::OK, ret_code);
}

/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestDictHandleGetValueSuite, case_name2)
{
    char char_value;
    dp::ErrorCode ret_code = _test_dict_handle->get_value<char>(1, &char_value);
    ASSERT_EQ('b', char_value);
    ASSERT_EQ(dp::OK, ret_code);
}

/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestDictHandleGetValueSuite, case_name3)
{
    double double_value;
    dp::ErrorCode ret_code = _test_dict_handle->get_value<double>(2, &double_value);
    ASSERT_EQ(3.14, double_value);
    ASSERT_EQ(dp::OK, ret_code);
}

/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestDictHandleGetValueSuite, case_name4)
{
    char* str_value = NULL;
    dp::ErrorCode ret_code = _test_dict_handle->get_value<char*>(3, &str_value);
    ASSERT_STREQ("teststring", str_value);
    ASSERT_EQ(dp::OK, ret_code);
}

/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestDictHandleGetValueSuite, case_name5)
{
    char* arr_value = NULL;
    size_t count = 0;
    dp::ErrorCode ret_code = _test_dict_handle->get_value<char>(4, &arr_value, &count);
    ASSERT_EQ('a', arr_value[0]);
    ASSERT_EQ('b', arr_value[1]);
    ASSERT_EQ('c', arr_value[2]);
    ASSERT_EQ('d', arr_value[3]);
    ASSERT_EQ(dp::OK, ret_code);
}

/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestDictHandleGetValueSuite, case_name6)
{
    char char_value;
    dp::ErrorCode ret_code = _test_dict_handle->get_value<char>(7, &char_value);
    ASSERT_EQ(dp::OVER_MAX_LEN, ret_code);
}
 
/**
 * @brief 
**/
class TestDictHandleGetUserDefinedValueSuite : public ::testing::Test{
    protected:
        TestDictHandleGetUserDefinedValueSuite(){};
        virtual ~TestDictHandleGetUserDefinedValueSuite(){};
        virtual void SetUp() {
            dp::ParseUserType<dp::UserTypeExample>::Func func \
                = boost::bind(&dp::parse_usertype_function, _1, _2);
            dp::ParseUserType<dp::UserTypeExample> user_type;
            user_type.set_func_map(func);

            _test_dict_handle = new dp::DictHandle;
            _test_dict_handle->split_line_columns("a\t100|3.333|c", "\t");
        };
        virtual void TearDown() {
            delete _test_dict_handle;
        };
        dp::DictHandle *_test_dict_handle;
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestDictHandleGetUserDefinedValueSuite, case_name1)
{
    dp::UserTypeExample user_type_value;
    dp::ErrorCode ret_code = _test_dict_handle->get_user_defined_value \
        <dp::UserTypeExample>(1, &user_type_value);
    ASSERT_EQ(100, user_type_value.int_value);
    ASSERT_EQ(3.333, user_type_value.double_value);
    ASSERT_EQ('c', user_type_value.char_value);
    ASSERT_EQ(dp::OK, ret_code);
}
 
 
