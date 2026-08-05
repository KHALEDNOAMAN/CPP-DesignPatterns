// Type Erasure
// Use Case: Hiding the concrete type of an object while preserving a common interface.
#include <iostream>
#include <memory>
class Any { struct Concept { virtual ~Concept() = default; virtual void print() const = 0; }; template<typename T> struct Model : Concept { T data; Model(T d) : data(std::move(d)) {} void print() const override { std::cout << data << "\n"; } }; std::unique_ptr<Concept> ptr; public: template<typename T> Any(T val) : ptr(std::make_unique<Model<T>>(std::move(val))) {} void print() const { ptr->print(); } };
int main() { Any a(10); Any b(std::string("Hello")); a.print(); b.print(); return 0; }
