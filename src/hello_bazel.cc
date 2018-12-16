/*============================================================================
 * Copyright (c) 2018 Fangjun Kuang
 * Email: fangjun.kuang at gmail.com
 *
 * Licensed under the MIT License.
 * Please refer to <root-path>/LICENSE for details.
 *============================================================================*/
#include <gflags/gflags.h>
#include <glog/logging.h>

#include "proto/student.pb.h"

DEFINE_int32(age, 18, "some info about the age");

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_alsologtostderr = true;
  FLAGS_colorlogtostderr = true;
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  kk::Student student;
  student.set_name("csu");
  student.mutable_age()->set_age(FLAGS_age);

  LOG(WARNING) << "\n" << student.DebugString();

  return 0;
}
