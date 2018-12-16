load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# gflags
# its name MUST be com_github_gflags_gflags !!
# Because glog requires that!
http_archive(
    name = "com_github_gflags_gflags",
    strip_prefix = "gflags-2.2.2",
    sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
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
    remote = "https://github.com/google/glog.git",
    commit = "1d900193d8e7e4ae3449231bbe7058933c1c7fba",
)

# protobuf
http_archive(
    name = "com_google_protobuf",
    strip_prefix = "protobuf-3.6.1",
    sha256 = "fd65488e618032ac924879a3a94fa68550b3b5bcb445b93b7ddf3c925b1a351f",
    urls = [
        "https://github.com/protocolbuffers/protobuf/releases/download/v3.6.1/protobuf-all-3.6.1.tar.gz",
    ],
)

