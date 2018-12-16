#!/bin/bash

filename="bazel-0.20.0-installer-darwin-x86_64.sh"

if [[ x"$1" == x"linux" ]]; then
  filename="bazel-0.20.0-installer-linux-x86_64.sh"
fi

url="https://github.com/bazelbuild/bazel/releases/download/0.20.0/$filename"
curl -OL  "$url"
chmod +x $filename
./$filename --user
