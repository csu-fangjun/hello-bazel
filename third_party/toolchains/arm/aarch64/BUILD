package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_toolchain_suite(
    name = "aarch64-compiler",
    toolchains = {
        "aarch64": "cc-compiler-aarch64",
    },
)

cc_toolchain(
    name = "cc-compiler-aarch64",
    all_files = ":linaro_linux_all_files",
    compiler_files = ":linaro_linux_compiler_files",
    cpu = "aarch64",
    dwp_files = ":empty",
    dynamic_runtime_libs = [":empty"],
    linker_files = ":linaro_linux_linker_files",
    objcopy_files = "//third_party/toolchains/arm/aarch64/linaro_linux_gcc:objcopy",
    static_runtime_libs = [":empty"],
    strip_files = "//third_party/toolchains/arm/aarch64/linaro_linux_gcc:strip",
    supports_param_files = 1,
)

filegroup(
    name = "linaro_linux_all_files",
    srcs = [
        "//third_party/toolchains/arm/aarch64/linaro_linux_gcc:tool-wrappers",
        "@gcc_linaro_7_3_1_aarch64_linux_gnu//:compiler_pieces",
    ],
)

filegroup(
    name = "linaro_linux_linker_files",
    srcs = [
        "//third_party/toolchains/arm/aarch64/linaro_linux_gcc:ar",
        "//third_party/toolchains/arm/aarch64/linaro_linux_gcc:gcc",
        "//third_party/toolchains/arm/aarch64/linaro_linux_gcc:ld",
        "@gcc_linaro_7_3_1_aarch64_linux_gnu//:compiler_pieces",
    ],
)

filegroup(
    name = "linaro_linux_compiler_files",
    srcs = [
        "//third_party/toolchains/arm/aarch64/linaro_linux_gcc:as",
        "//third_party/toolchains/arm/aarch64/linaro_linux_gcc:gcc",
        "//third_party/toolchains/arm/aarch64/linaro_linux_gcc:ld",
    ],
)

filegroup(
    name = "empty",
    srcs = [],
)
