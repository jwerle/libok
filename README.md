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

#define OK_VERSION "0.2.0"

/**
 * No-op/void `ok()` function
 */
#define okx(...) (void) (0);

/**
 * Increments ok count and
 * outputs a message to stdout
 */

void
ok (char *message, ...);

/**
 * Completes tests and asserts that
 * the expected test count matches the
 * actual test count if the expected
 * count is greater than 0
 */

void
ok_done (void);

/**
 * Sets the expectation count
 */

void
ok_expect (int expected);

/**
 * Returns the expected count
 */

int
ok_expected ();

/**
 * Returns the ok count
 */

int
ok_count ();

/**
 * Resets count and expected counters
 */

void
ok_reset ();
```

## license

MIT
