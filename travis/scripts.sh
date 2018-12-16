#!/bin/bash

bazel build //src:hello_bazel
./bazel-bin/src/hello_bazel

bazel build //src:hello_test
./bazel-bin/src/hello_test

