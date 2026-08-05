// Template Method
// Use Case: Defining the skeleton of an algorithm in an operation, deferring some steps to subclasses.
#include <iostream>
class AbstractClass { public: void templateMethod() { primitiveOperation1(); primitiveOperation2(); } virtual void primitiveOperation1() = 0; virtual void primitiveOperation2() = 0; virtual ~AbstractClass() = default; };
class ConcreteClass : public AbstractClass { public: void primitiveOperation1() override { std::cout << "Op1\n"; } void primitiveOperation2() override { std::cout << "Op2\n"; } };
int main() { ConcreteClass c; c.templateMethod(); return 0; }
