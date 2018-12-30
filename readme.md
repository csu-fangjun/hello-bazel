|<sub>Mac OS/Linux</sub>|
|:---:|
|[![Build Status](https://travis-ci.com/csu-fangjun/hello-bazel.svg?branch=master)](https://travis-ci.com/csu-fangjun/hello-bazel)|


## Use Bazel for C++ Programming

I find that Bazel is pretty handy for C++ programming
and this repository contains some sample code about
Bazel during the learning process.

It can be used as a template for later development.

## Install Bazel

Go to <https://github.com/bazelbuild/bazel/releases> and download a `.sh`
file for the corresponding platform.

For example,

```sh
wget https://github.com/bazelbuild/bazel/releases/download/0.20.0/bazel-0.20.0-installer-darwin-x86_64.sh
chmod +x bazel-0.20.0-installer-darwin-x86_64.sh
./bazel-0.20.0-installer-darwin-x86_64.sh --user
export PATH=$HOME/bin:${PATH}
```

To view the current version, run `bazel version`.

## Commandline Completion

When bazel is installed to `$HOME/bin`, a file named
`bazel-complete.bash` is installed to `$HOME/.bazel/bin`
simultaneously.

Add the following line to `$HOME/.bash_profile` (macOS)
or to `$HOME/.bashrc` (Linux):

```sh
source $HOME/.bazel/bin/bazel-complete.bash
```

## Auto Format BUILD files

Refer to <https://github.com/bazelbuild/buildtools/blob/master/buildifier/README.md>.

A quick guide is as follows:

```
go get github.com/bazelbuild/buildtools/buildifier
cd $HOME/go/src/github.com/bazelbuild/buildtools/buildifier
bazel build //buildifier
export PATH=$HOME/go/bin:${PATH}
```
