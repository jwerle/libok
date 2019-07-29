
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ok.h>

int
main (void) {
  okx("foo", 123, 0);
  ok_expect(4);
  assert(4 == ok_expected());
  ok("beep");
  assert(1 == ok_count());
  ok("boop");
  assert(2 == ok_count());
  ok("biz");
  assert(3 == ok_count());
  ok("baz");
  assert(4 == ok_count());
  ok_done();
  return 0;
}
