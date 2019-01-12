/*============================================================================
 * Copyright (c) 2019 Fangjun Kuang
 * Email: fangjun.kuang at gmail.com
 *
 * Licensed under the MIT License.
 * Please refer to <root-path>/LICENSE for details.
 *============================================================================*/
#include <stdarg.h>

#include <gtest/gtest.h>

/*
 * References:
 *
 * - "Using GNU C __attribute__",
 *   http://unixwiz.net/techtips/gnu-c-attributes.html
 *
 */

#ifdef __GNUC__
#warning This is a gcc compiler!

static int unused_func_warning(int a1, int a2) { return a1 + 2; }

__attribute__((unused)) static int unused_func_no_warning(int a1, int a2) {
  return a1 + 2;
}

TEST(Gcc, unused) {
  int warning_unused_var; // warning: unused variable 'warning_unused_var'
                          // [-Wunused-variable]
  int no_warning_unused_var __attribute__((unused)); // no warning
  unused_func_no_warning(1, 2);
}

// format is used to issue compiler warnings
// if the user specifies an incorrect argument
// that does not statisify the format specifier.
// index starts from 1.
// format is the first index.
// the argument to be checked is the 3rd index.
__attribute__((format(printf, 1, 2))) static void my_printf(const char *format,
                                                            ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}

// format is the 2nd index.
// the argument to be checked is the 3rd index.
__attribute__((format(printf, 2, 3))) static void
my_printf2(int id, const char *format, ...) {
  va_list args;
  va_start(args, format);
  printf("id is: %d, ", id);
  vprintf(format, args);
  va_end(args);
}

TEST(Gcc, format_printf) {
  my_printf("hello %s\n", "world");

  /* warning: format specifies type 'char *' but the argument has type 'int'
   * [-Wformat] */
  // my_printf("hello %s\n", 1);

  my_printf2(1, "Welt");
}

__attribute__((nonnull(1, 2))) static void my_copy(char *dst, const char *src,
                                                   size_t n) {
  if (!n)
    return;
  memcpy(dst, src, n);
}

TEST(Gcc, nonnull) {
  /* warning: null passed to a called that requires a non-null argument
   * [-Wnonnull] */
  my_copy(nullptr, NULL, 0); // it can check both nullptr and NULL
}

__attribute__((deprecated("msg for deprecated"))) static void
my_deprecated_func() {}
TEST(Gcc, deprecated) {
  my_deprecated_func();
} /*warning: 'void my_deprecated_func()' is deprecated: msg for deprecated
     [-Wdeprecated-declarations]*/

__attribute__((warning(" msg for warning"))) static void my_warning_func() {}
TEST(Gcc, warning) {
  my_warning_func();
} /* warning: call to 'my_warning_func' declared with attribute warning: msg for
     warning */

__attribute__((error(" msg for error"))) void my_error_func() {}
TEST(Gcc, error) {
  // my_error_func();
} /* error: call to 'my_error_func' declared with attribute error: msg for error
     */

#else
#warning This is not a gcc compiler, skip the test!
#endif

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
