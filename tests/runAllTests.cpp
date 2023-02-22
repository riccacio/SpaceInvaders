#include "lib/googletest/include/gtest/gtest.h"

using namespace std;

TEST(Example, EmptyTest) {
    ASSERT_FALSE(1 == 2);
}

TEST(Example, EmptyTest2) {
    ASSERT_TRUE(1 == 2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}