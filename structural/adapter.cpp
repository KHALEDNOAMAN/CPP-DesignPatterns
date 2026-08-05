// Adapter
// Use Case: Converting the interface of a class into another interface clients expect.
#include <iostream>
class Target { public: virtual void request() const { std::cout << "Target request\n"; } virtual ~Target() = default; };
class Adaptee { public: void specificRequest() const { std::cout << "Adaptee specific request\n"; } };
class Adapter : public Target { Adaptee adaptee; public: void request() const override { adaptee.specificRequest(); } };
int main() { Adapter adapter; adapter.request(); return 0; }
