#!/bin/bash

bazel build //src:hello

./bazel-bin/src/hello
