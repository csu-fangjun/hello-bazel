load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# gflags
# its name MUST be com_github_gflags_gflags !!
# Because glog requires that!
http_archive(
    name = "com_github_gflags_gflags",
    sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
    strip_prefix = "gflags-2.2.2",
    urls = [
        "https://github.com/gflags/gflags/archive/v2.2.2.tar.gz",
    ],
)

'''
# use git for gflags
git_repository(
    name   = "com_github_gflags_gflags",
    remote = "https://github.com/gflags/gflags.git",
    commit = "e171aa2d15ed9eb17054558e0b3a6a413bb01067",
    # tag = "v2.2.2",
)
'''

# do not use http archive for glog
# current version of glog is 0.3.5 released in 2017.
# use git instead for glog!

git_repository(
    name = "com_google_glog",
    commit = "1d900193d8e7e4ae3449231bbe7058933c1c7fba",
    remote = "https://github.com/google/glog.git",
)

# protobuf
http_archive(
    name = "com_google_protobuf",
    sha256 = "fd65488e618032ac924879a3a94fa68550b3b5bcb445b93b7ddf3c925b1a351f",
    strip_prefix = "protobuf-3.6.1",
    urls = [
        "https://github.com/protocolbuffers/protobuf/releases/download/v3.6.1/protobuf-all-3.6.1.tar.gz",
    ],
)

# google test
http_archive(
    name = "com_google_gtest",
    sha256 = "9bf1fe5182a604b4135edc1a425ae356c9ad15e9b23f9f12a02e80184c3a249c",
    strip_prefix = "googletest-release-1.8.1",
    urls = [
        "https://github.com/google/googletest/archive/release-1.8.1.tar.gz",
    ],
)

new_http_archive(
    name = "gcc_linaro_7_3_1_aarch64_linux_gnu",
    build_file = "third_party/toolchains/arm/aarch64/aarch64_compiler.BUILD",
    sha256 = "73eed74e593e2267504efbcf3678918bb22409ab7afa3dc7c135d2c6790c2345",
    strip_prefix = "gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu",
    urls = [
        "https://releases.linaro.org/components/toolchain/binaries/7.3-2018.05/aarch64-linux-gnu/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu.tar.xz",
    ],
)
