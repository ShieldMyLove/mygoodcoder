#include <gtest/gtest.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include "parse_user_type.h"
#include "user_defined_type.h"
	
	
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/**
 * @brief 
**/
class TestParseUserTypeParseStrDefinedTypeSuite : public ::testing::Test{
    protected:
        TestParseUserTypeParseStrDefinedTypeSuite(){};
        virtual ~TestParseUserTypeParseStrDefinedTypeSuite(){};
        virtual void SetUp() {
            _test_parse_user_type = new dp::ParseUserType<dp::UserTypeExample>();
            dp::ParseUserType<dp::UserTypeExample>::Func func = \
                boost::bind(&dp::parse_usertype_function, _1, _2);
            dp::ParseUserType<dp::UserTypeExample> user_type;
            user_type.set_func_map(func);
        };
        virtual void TearDown() {
            delete _test_parse_user_type;
        };
        dp::ParseUserType<dp::UserTypeExample> *_test_parse_user_type;
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestParseUserTypeParseStrDefinedTypeSuite, case_name1)
{
    dp::UserTypeExample user_type_value;
    _test_parse_user_type->parse_str_defined_type("1|1.23|a", &user_type_value);
    ASSERT_EQ(1, user_type_value.int_value);
    ASSERT_EQ(1.23, user_type_value.double_value);
    ASSERT_EQ('a', user_type_value.char_value);

}
 
