#include <iostream>
class Base { public: void foo() { do_foo(); } private: virtual void do_foo() = 0; };
int main() { return 0; }