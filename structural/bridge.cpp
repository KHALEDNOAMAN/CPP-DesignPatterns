// Bridge
// Use Case: Decoupling an abstraction from its implementation so that the two can vary independently.
#include <iostream>
#include <memory>
class Implementor { public: virtual void operationImpl() = 0; virtual ~Implementor() = default; };
class ConcreteImplementorA : public Implementor { public: void operationImpl() override { std::cout << "ConcreteImplementorA\n"; } };
class Abstraction { protected: std::shared_ptr<Implementor> impl; public: Abstraction(std::shared_ptr<Implementor> i) : impl(i) {} virtual void operation() = 0; virtual ~Abstraction() = default; };
class RefinedAbstraction : public Abstraction { public: RefinedAbstraction(std::shared_ptr<Implementor> i) : Abstraction(i) {} void operation() override { impl->operationImpl(); } };
int main() { auto impl = std::make_shared<ConcreteImplementorA>(); RefinedAbstraction abs(impl); abs.operation(); return 0; }
