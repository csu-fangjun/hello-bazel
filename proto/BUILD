# refer to https://github.com/cgrushko/proto_library/blob/master/WORKSPACE
# and https://github.com/cgrushko/proto_library/tree/master/src

package(default_visibility = ["//visibility:public"])

cc_proto_library(
    name = "student_cc_proto",
    deps = [":student_proto"]
)

proto_library(
    name = "student_proto",
    srcs = ["student.proto"],
    deps = [":age_proto"]
)

proto_library(
    name = "age_proto",
    srcs = ["age.proto"],
)

