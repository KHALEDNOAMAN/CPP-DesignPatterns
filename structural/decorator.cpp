// Decorator
// Use Case: Attaching additional responsibilities to an object dynamically.
#include <iostream>
#include <memory>
class Component { public: virtual void operation() = 0; virtual ~Component() = default; };
class ConcreteComponent : public Component { public: void operation() override { std::cout << "ConcreteComponent\n"; } };
class Decorator : public Component { protected: std::shared_ptr<Component> component; public: Decorator(std::shared_ptr<Component> c) : component(c) {} void operation() override { component->operation(); } };
class ConcreteDecorator : public Decorator { public: ConcreteDecorator(std::shared_ptr<Component> c) : Decorator(c) {} void operation() override { Decorator::operation(); std::cout << "ConcreteDecorator\n"; } };
int main() { auto c = std::make_shared<ConcreteComponent>(); auto d = std::make_shared<ConcreteDecorator>(c); d->operation(); return 0; }
