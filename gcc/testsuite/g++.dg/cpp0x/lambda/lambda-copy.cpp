// { dg-do "compile" }
// { dg-options "-std=c++0x"}

template<typename F>
void call(F f) { f(); }

int main() {
  int i = 1, j = 2;
  call([i, j] () -> void { i = 0; j = 0; });
  assert(i == 1);
  assert(j == 2);

  //call([] () -> void { i; }); // { dg-error: "`i' is not in scope" }
  //call([1] () -> void {}); // { dg-error: "expected identifier" }

  return 0;
}

