#include <assert.h>
#include "ok.h"

int main (void) {
  okx("foo", 123, 0);
  ok_expect(4);
  ok_explain(
    "this is a libok test\n"
    "this is the explaination of that test\n"
    "it is in multiline comment block"
  );
  assert(4 == ok_expected());
  ok("beep");
  assert(1 == ok_count());
  ok("boop");
  assert(2 == ok_count());
  ok("biz");
  assert(3 == ok_count());
  ok("baz");
  assert(4 == ok_count());

  if (ok_done() != true) {
    return 1;
  }

  ok_reset();

  ok_explain(
    "this next test should fail\n"
    "the `ok_done()` function should return `false`"
  );
  ok("first");
  notok("oops");

  if (ok_done() != false) {
    return 1;
  }

  return 0;
}
