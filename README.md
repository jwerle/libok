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
```

## license

MIT
