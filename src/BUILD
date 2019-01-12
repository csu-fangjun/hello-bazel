cc_binary(
    name = "hello_arm",
    srcs = ["hello_arm.cc"],
)

cc_binary(
    name = "hello_bazel",
    srcs = ["hello_bazel.cc"],
    deps = [
        "//proto:student_cc_proto",
        "@com_github_gflags_gflags//:gflags",
        "@com_google_glog//:glog",
    ],
)

cc_test(
    name = "hello_test",
    srcs = ["hello_test.cc"],
    deps = [
        "@com_google_gtest//:gtest",
    ],
)

cc_test(
    name = "predefined_macros_test",
    srcs = ["predefined_macros_test.cc"],
    deps = [
        "@com_google_glog//:glog",
        "@com_google_gtest//:gtest",
    ],
)

cc_test(
    name = "type_traits_test",
    srcs = ["type_traits_test.cc"],
    deps = [
        "@com_google_gtest//:gtest",
    ],
)

cc_test(
    name = "gcc_attributes_test",
    srcs = ["gcc_attributes_test.cc"],
    deps = [
        "@com_google_gtest//:gtest",
    ],
)

cc_test(
    name = "clang_attributes_test",
    srcs = ["clang_attributes_test.cc"],
    deps = [
        "@com_google_gtest//:gtest",
    ],
)
