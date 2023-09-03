#include "../googletest/googletest/include/gtest/gtest.h"
#include "../lib.h"

TEST(TestGroupName, Subtest_1) {
    ASSERT_TRUE(version() > 5);
}

TEST(TestGroupName, Subtest_2) {
    ASSERT_TRUE(version() != 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

