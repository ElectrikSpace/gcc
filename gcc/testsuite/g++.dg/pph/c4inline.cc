// pph asm xdiff 36250
// xfail BOGUS DUPFUN
//
// Emitting a second copy of the inline function f.
// With comdat, the linker may paper over the differences.

#include "c0inline1.h"
#include "c0inline2.h"

int main()
{
  return g() + h();
}
