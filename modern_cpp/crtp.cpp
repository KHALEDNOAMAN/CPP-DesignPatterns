// Curiously Recurring Template Pattern (CRTP)
// Use Case: Static polymorphism, replacing virtual functions with compile-time polymorphism.
#include <iostream>
template<typename Derived> class Base { public: void interface() { static_cast<Derived*>(this)->implementation(); } };
class Derived : public Base<Derived> { public: void implementation() { std::cout << "Derived implementation\n"; } };
int main() { Derived d; d.interface(); return 0; }
