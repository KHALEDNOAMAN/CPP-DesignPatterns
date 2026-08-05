// Mediator
// Use Case: Defining an object that encapsulates how a set of objects interact.
#include <iostream>
#include <string>
class Colleague;
class Mediator { public: virtual void notify(Colleague* sender, std::string event) = 0; virtual ~Mediator() = default; };
class Colleague { protected: Mediator* mediator; public: Colleague(Mediator* m = nullptr) : mediator(m) {} void setMediator(Mediator* m) { mediator = m; } };
class Component1 : public Colleague { public: void doA() { std::cout << "Component1 does A.\n"; mediator->notify(this, "A"); } };
class ConcreteMediator : public Mediator { Component1* c1; public: ConcreteMediator(Component1* c1) : c1(c1) { this->c1->setMediator(this); } void notify(Colleague* sender, std::string event) override { if (event == "A") std::cout << "Mediator reacts on A\n"; } };
int main() { Component1 c1; ConcreteMediator m(&c1); c1.doA(); return 0; }
