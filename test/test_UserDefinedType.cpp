#include <gtest/gtest.h>
#include "user_defined_type.h"
	
	
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/**
 * @brief 
**/
class TestParseUserTypeFunctionSuite : public ::testing::Test{
    protected:
        TestParseUserTypeFunctionSuite(){};
        virtual ~TestParseUserTypeFunctionSuite(){};
        virtual void SetUp() {
            //Called befor every TEST_F(test_parse_usertype_function_suite, *)
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_parse_usertype_function_suite, *)
        };
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestParseUserTypeFunctionSuite, case_name1)
{
    dp::UserTypeExample user_type;
    dp::parse_usertype_function("1|1.23|a", &user_type);
    ASSERT_EQ(1, user_type.int_value);
    ASSERT_EQ(1.23, user_type.double_value);
    ASSERT_EQ('a', user_type.char_value);
}
 
