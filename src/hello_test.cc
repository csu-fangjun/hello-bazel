/*============================================================================
 * Copyright (c) 2018 Fangjun Kuang
 * Email: fangjun.kuang at gmail.com
 *
 * Licensed under the MIT License.
 * Please refer to <root-path>/LICENSE for details.
 *============================================================================*/
#include <gtest/gtest.h>

TEST(HelloTest, Case1) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

