/*============================================================================
 * Copyright (c) 2018 Fangjun Kuang
 * Email: fangjun.kuang at gmail.com
 *
 * Licensed under the MIT License.
 * Please refer to <root-path>/LICENSE for details.
 *============================================================================*/
#include <gflags/gflags.h>
#include <glog/logging.h>

DEFINE_int32(year, 1989, "some info about the year");

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_alsologtostderr = true;
  FLAGS_colorlogtostderr = true;

  gflags::ParseCommandLineFlags(&argc, &argv, true);


  LOG(WARNING) << "year is: " << FLAGS_year << "\n";

  return 0;
}
