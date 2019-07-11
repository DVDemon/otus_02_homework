#include "lib.h"
#include <gtest/gtest.h>

TEST(test_01, basic_test_set)
{
    ip_type ip=to_ip(std::string("0.0.0.0"));
    ASSERT_TRUE((std::get<0>(ip)==0)&&
                (std::get<1>(ip)==0)&&
                (std::get<2>(ip)==0)&&
                (std::get<3>(ip)==0));
}

TEST(test_02, basic_test_set)
{
    ip_type ip=to_ip(std::string("255.255.255.255"));
    ASSERT_TRUE((std::get<0>(ip)==255)&&
                (std::get<1>(ip)==255)&&
                (std::get<2>(ip)==255)&&
                (std::get<3>(ip)==255));
}

TEST(test_03, basic_test_set)
{
    ip_type ip=to_ip(std::string(" 1.2.3.4      "));
    ASSERT_TRUE((std::get<0>(ip)==1)&&
                (std::get<1>(ip)==2)&&
                (std::get<2>(ip)==3)&&
                (std::get<3>(ip)==4));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}