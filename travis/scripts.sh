#!/bin/bash

bazel build //...
bazel test //...

if [[ x"$1" == x"linux" ]]; then
  echo "------build aarch64------"

  export PATH=${HOME}/software/qemu/bin:${PATH}
  export LD_LIBRARY_PATH=$HOME/software/linaro/aarch64-linux-gnu/libc/lib:${LD_LIBRARY_PATH}
  bazel build --config=aarch64 //...
  qemu-aarch64 bazel-bin/src/hello_arm
  qemu-aarch64 bazel-bin/src/hello_bazel
  qemu-aarch64 bazel-bin/src/hello_test
  # bazel run --run_under=qemu-aarch64 --config=aarch64 //src:hello_arm
  # bazel run --run_under=qemu-aarch64 --config=aarch64 //src:hello_bazel
  # bazel test --run_under=qemu-aarch64 --config=aarch64 //src:all
fi

