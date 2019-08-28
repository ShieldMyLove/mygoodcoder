#include <gtest/gtest.h>
#include "parse_comm_type.h"
	
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/**
 * @brief 
**/
class TestParseCommTypeParseStrDefinedTypeSuite : public ::testing::Test{
    protected:
        TestParseCommTypeParseStrDefinedTypeSuite(){};
        virtual ~TestParseCommTypeParseStrDefinedTypeSuite(){};
        virtual void SetUp() {
            _test_parse_commtype = new dp::ParseCommType<int>();
        };
        virtual void TearDown() {
            delete _test_parse_commtype;
        };
        dp::ParseCommType<int> *_test_parse_commtype;
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestParseCommTypeParseStrDefinedTypeSuite, case_name1)
{
    const std::string column = "1,2,3";
    int *arr_value;
    size_t count;
    _test_parse_commtype->parse_str_defined_type(column, &arr_value, &count);
    ASSERT_EQ(1, arr_value[0]);
    ASSERT_EQ(2, arr_value[1]);
    ASSERT_EQ(3, arr_value[2]);
    ASSERT_EQ(3, (int)count);
}
 
