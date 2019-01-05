/*============================================================================
 * Copyright (c) 2019 Fangjun Kuang
 * Email: fangjun.kuang at gmail.com
 *
 * Licensed under the MIT License.
 * Please refer to <root-path>/LICENSE for details.
 *============================================================================*/

/*
 * References:
 *
 * 1. https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html
 *
 */

#include <glog/logging.h>
#include <gtest/gtest.h>

/*
 * For gcc:
 *  199711L  ---> 1998 C++ standard
 *  201103L  ---> 2011 C++ standard
 *  201402L  ---> 2014 C++ standard
 *  201703L  ---> 2017 C++ standard
 */
TEST(PredefinedMacrosTest, cplusplus) {
#ifdef __cplusplus
  LOG(INFO) << "__cplusplus: " << __cplusplus;
#else
  LOG(INFO) << "__cplusplus is not defined!";
#endif
}

TEST(PredefinedMacrosTest, FILE_LINE) {
  LOG(INFO) << "__FILE__: " << __FILE__;
  LOG(INFO) << "__LINE__: " << __LINE__;
}

TEST(PredefinedMacrosTest, architecture) {
#ifdef __x86_64
  LOG(INFO) << "__x86_64: " << __x86_64;
#else
  LOG(INFO) << "__x86_64 is not defined";
#endif

#ifdef __x86_64__
  LOG(INFO) << "__x86_64__: " << __x86_64__;
#else
  LOG(INFO) << "__x86_64__ is not defined";
#endif
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  google::InitGoogleLogging(argv[0]);
  FLAGS_alsologtostderr = true;
  FLAGS_colorlogtostderr = true;
  return RUN_ALL_TESTS();
}
