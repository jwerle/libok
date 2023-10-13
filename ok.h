/**
 * `ok.h` - libok
 *
 * Copyright (C) 2014-2023 Joseph Werle <joseph.werle@gmail.com>
 */

#ifndef OK_H
#define OK_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * libok version
 */
#ifndef OK_VERSION
#define OK_VERSION "0.5.0"
#endif

/**
 * No-op/void `ok()` function
 */
#ifndef okx
#define okx(...) (void) (0);
#endif

/**
 * Allow for custom `printf` implementation.
 */
#if !defined(LIBOK_PRINTF)
#define LIBOK_PRINTF(...) (printf(__VA_ARGS__))
#endif

/**
 * Allow for custom `fprintf` implementation.
 */
#if !defined(LIBOK_FPRINTF)
#define LIBOK_FPRINTF(...) (fprintf(__VA_ARGS__))
#endif

/**
 * Configure the need for a newline ('\n') in a `printf` call.
 */
#if !defined(LIBOK_PRINTF_NEEDS_NEWLINE)
#define LIBOK_PRINTF_NEEDS_NEWLINE 1
#endif

/**
 * Configure the need for a newline ('\n') in a `fprintf` call.
 */
#if !defined(LIBOK_FPRINTF_NEEDS_NEWLINE)
#define LIBOK_FPRINTF_NEEDS_NEWLINE LIBOK_PRINTF_NEEDS_NEWLINE
#endif

/**
 * Increments ok count and
 * outputs a message to stdout
 */
#define ok(format, ...) ({                                                     \
  LIBOK_PRINTF("ok %d ", ok_count_inc());                                      \
  LIBOK_PRINTF(format, ##__VA_ARGS__);                                         \
  if (LIBOK_PRINTF_NEEDS_NEWLINE) {                                            \
    LIBOK_PRINTF("\n");                                                        \
  }                                                                            \
})

/**
 * Completes tests and asserts that
 * the expected test count matches the
 * actual test count if the expected
 * count is greater than 0
 */
void ok_done (void);

/**
 * Sets the expectation count
 */
void ok_expect (int);

/**
 * Returns the expected count
 */
int ok_expected (void);

/**
 * Returns the ok count
 */
int ok_count (void);
int ok_count_inc (void);

/**
 * Resets count and expected counters
 */
void ok_reset (void);

#if defined(LIBOK_INCLUDE_IMPLEMENTATION)

static int ok_count_;
static int ok_expected_;

void ok_done (void) {
  if (0 != ok_expected() && ok_count() != ok_expected()) {
    if (ok_expected() > ok_count()) {
      LIBOK_FPRINTF(stderr, "expected number of success conditions not met.");
      if (LIBOK_FPRINTF_NEEDS_NEWLINE) {
        LIBOK_FPRINTF(stderr, "\n");
      }
    } else {
      LIBOK_FPRINTF(stderr,
        "expected number of success conditions is less than the "
        "number of given success conditions.");
      if (LIBOK_FPRINTF_NEEDS_NEWLINE) {
        LIBOK_FPRINTF(stderr, "\n");
      }
    }
    exit(1);
  }

  LIBOK_PRINTF("1..%d", ok_count());
  if (LIBOK_PRINTF_NEEDS_NEWLINE) {
    LIBOK_PRINTF("\n");
  }
}

void ok_expect (int expected) {
  ok_expected_ = expected;
}

int ok_expected (void) {
  return ok_expected_;
}

int ok_count_inc (void) {
  return ++ok_count_;
}

int ok_count (void) {
  return ok_count_;
}

void ok_reset (void) {
  ok_count_ = 0;
  ok_expected_ = 0;
}

#endif
#ifdef __cplusplus
}
#endif
#endif
