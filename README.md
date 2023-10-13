libok
=====

Super tiny tap output library

## install

**clib:**

```sh
$ clib install jwerle/libok
```

**source:**

```sh
$ git clone https://github.com/jwerle/libok.git
$ cd libok
$ make
$ make install
```

## usage

```c
ok_expect(1);
ok("my feature works");
ok_done();
```

## api

```c
/**
 * libok version
 */
#ifndef OK_VERSION
#define OK_VERSION "0.6.3"
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
  if (ok_count() == 0 && ok_failed() == 0) ok_begin(NULL);                     \
  int count = ok_count_inc() + ok_failed();                                    \
  LIBOK_PRINTF("ok %d - " format, count, ##__VA_ARGS__);                       \
  if (LIBOK_PRINTF_NEEDS_NEWLINE) {                                            \
    LIBOK_PRINTF("\n");                                                        \
  }                                                                            \
})

/**
 * Outputs a a "not ok"  message to stdout.
 * Increments not ok count.
 */
#define notok(format, ...) ({                                                  \
  if (ok_count() == 0 && ok_failed() == 0) ok_begin(NULL);                     \
  int count = ok_count_inc() + ok_failed();                                    \
  LIBOK_PRINTF("not ok %d - " format, count, ##__VA_ARGS__);                   \
                                                                               \
  if (LIBOK_PRINTF_NEEDS_NEWLINE) {                                            \
    LIBOK_PRINTF("\n");                                                        \
  }                                                                            \
                                                                               \
  LIBOK_PRINTF("   ---");                                                      \
  if (LIBOK_PRINTF_NEEDS_NEWLINE) {                                            \
    LIBOK_PRINTF("\n");                                                        \
  }                                                                            \
                                                                               \
  LIBOK_PRINTF("   severity: fail");                                           \
  if (LIBOK_PRINTF_NEEDS_NEWLINE) {                                            \
    LIBOK_PRINTF("\n");                                                        \
  }                                                                            \
                                                                               \
  LIBOK_PRINTF("   stack:    |-");                                             \
  if (LIBOK_PRINTF_NEEDS_NEWLINE) {                                            \
    LIBOK_PRINTF("\n");                                                        \
  }                                                                            \
                                                                               \
  LIBOK_PRINTF("         at  %s (%s:%d)",                                      \
    __FUNCTION__,                                                              \
    __FILE__,                                                                  \
    __LINE__                                                                   \
  );                                                                           \
  if (LIBOK_PRINTF_NEEDS_NEWLINE) {                                            \
    LIBOK_PRINTF("\n");                                                        \
  }                                                                            \
                                                                               \
  LIBOK_PRINTF("   ...");                                                      \
  if (LIBOK_PRINTF_NEEDS_NEWLINE) {                                            \
    LIBOK_PRINTF("\n");                                                        \
  }                                                                            \
})

/**
 * Called at the beginning of a test with an optional (NULL) label.
 */
void ok_begin (const char *label);

/**
 * Can be used to printf a comment.
 */
void ok_comment (const char *comment);

/**
 * Can be used to provide a multiline test explaination.
 */
void ok_explain (const char *explaination);

/**
 * Can be used to issue an emergency "Bail out!" statement with an
 * optional comment.
 */
void ok_bail (const char *comment);

/**
 * Completes tests and asserts that
 * the expected test count matches the
 * actual test count if the expected
 * count is greater than 0
 */
bool ok_done (void);

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
 * Returns the not ok count
 */
int ok_failed (void);
int ok_failed_inc (void);

/**
 * Resets count and expected counters
 */
void ok_reset (void);
```

## license

MIT
