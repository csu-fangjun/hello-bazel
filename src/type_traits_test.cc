/*============================================================================
 * Copyright (c) 2019 Fangjun Kuang
 * Email: fangjun.kuang at gmail.com
 *
 * Licensed under the MIT License.
 * Please refer to <root-path>/LICENSE for details.
 *============================================================================*/
#include <type_traits>

#include <gtest/gtest.h>

TEST(TypeTraitsTest, integral_constant) {
  std::integral_constant<int, 3> d;
  int a = 1;
  a = a + d; // use implicit conversion
  EXPECT_EQ(a, 4);

#if __cplusplus > 201103L
  a = 2 + d(); // use operator(), since c++14
  EXPECT_EQ(a, 5);
#endif

  a = 3 + d.value; // use static data member
  EXPECT_EQ(a, 6);

  a = 4 + std::integral_constant<int, 3>::value;
  EXPECT_EQ(a, 7);

  static_assert(
      std::is_same<std::true_type, std::integral_constant<bool, true>>::value,
      "");
  static_assert(
      std::is_same<std::false_type, std::integral_constant<bool, false>>::value,
      "");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
