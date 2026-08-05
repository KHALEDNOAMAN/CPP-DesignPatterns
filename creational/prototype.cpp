// Prototype
// Use Case: Specifying the kinds of objects to create using a prototypical instance.
#include <iostream>
#include <memory>
class Prototype { public: virtual std::unique_ptr<Prototype> clone() const = 0; virtual void print() const = 0; virtual ~Prototype() = default; };
class ConcretePrototype : public Prototype { int value; public: ConcretePrototype(int v) : value(v) {} std::unique_ptr<Prototype> clone() const override { return std::make_unique<ConcretePrototype>(*this); } void print() const override { std::cout << "Value: " << value << "\n"; } };
int main() { ConcretePrototype p1(10); auto p2 = p1.clone(); p2->print(); return 0; }
