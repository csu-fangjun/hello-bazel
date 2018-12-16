
cc_binary(
    name = "hello_bazel",
    srcs = ["hello_bazel.cc"],
    deps = [
        "//proto:student_cc_proto",
        "@com_github_gflags_gflags//:gflags",
        "@com_google_glog//:glog"
    ],
)

cc_test(
    name = "hello_test",
    srcs = ["hello_test.cc"],
    deps = [
        "@com_google_gtest//:gtest"
    ],
)
