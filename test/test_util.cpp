
#include "util.h"
#include <gtest/gtest.h>
	
	
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/**
 * @brief 
**/
class TestUtilSplitStringSuite : public ::testing::Test{
    protected:
        TestUtilSplitStringSuite(){};
        virtual ~TestUtilSplitStringSuite(){};
        virtual void SetUp() {
            //Called befor every TEST_F(test_Util_split_string_suite, *)
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_Util_split_string_suite, *)
        };
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(TestUtilSplitStringSuite, case_name1)
{
    std::vector<int> ret_vec;
    dp::Util::split_string("1\t2\t3", "\t", &ret_vec);
    ASSERT_EQ(1, ret_vec[0]);
    ASSERT_EQ(2, ret_vec[1]);
    ASSERT_EQ(3, ret_vec[2]);
}
 
