/*============================================================================
 * Copyright (c) 2019 Fangjun Kuang
 * Email: fangjun.kuang at gmail.com
 *
 * Licensed under the MIT License.
 * Please refer to <root-path>/LICENSE for details.
 *============================================================================*/
#include <gtest/gtest.h>

/*
 *
 * Refer to
 *  - "Clang Language Extensions" at
 *    http://clang.llvm.org/docs/LanguageExtensions.html
 *
 */

#ifdef __clang__
#warning This is a clang compiler!

TEST(ClangVersion, version) {
  printf(" major: %d\n", __clang_major__);
  printf(" minor: %d\n", __clang_minor__);
  printf(" patch: %d\n", __clang_patchlevel__);
  printf(" version: %s\n", __clang_version__);
}

#else
#warning This is not a clang compiler, skip the test!
#endif

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
