// Move Semantics
// Use Case: Optimizing performance by moving resources instead of copying them.
#include <iostream>
#include <utility>
class Moveable { int* data; public: Moveable(int val) { data = new int(val); } ~Moveable() { delete data; } Moveable(Moveable&& other) noexcept : data(other.data) { other.data = nullptr; } Moveable& operator=(Moveable&& other) noexcept { if (this != &other) { delete data; data = other.data; other.data = nullptr; } return *this; } };
int main() { Moveable a(10); Moveable b = std::move(a); return 0; }
