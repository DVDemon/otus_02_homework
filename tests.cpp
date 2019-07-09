#include "lib.h"
#include <gtest/gtest.h>

TEST(basic_test_set, test_01)
{
    ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}