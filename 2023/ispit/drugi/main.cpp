#include <iostream>
using std::cout, std::endl;

struct Foo {
  Foo() { cout << "DC" << endl; }
  Foo(const Foo &) { cout << "CC" << endl; }
  ~Foo() { cout << "D" << endl; }
};

void foo(Foo b) { cout << "Unutar foo" << endl; }

Foo a;

int main() {
  cout << "Pocinjemo" << endl;
  Foo &b{a};
  cout << "Nastavljamo" << endl;
  foo(b);
  cout << "Idemo dalje" << endl;
  Foo{};
  cout << "Zavrsavamo" << endl;
  return 0;
}
