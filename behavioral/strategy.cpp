// Strategy
// Use Case: Defining a family of algorithms, encapsulating each one, and making them interchangeable.
#include <iostream>
#include <memory>
class Strategy { public: virtual void execute() = 0; virtual ~Strategy() = default; };
class ConcreteStrategyA : public Strategy { public: void execute() override { std::cout << "ConcreteStrategyA\n"; } };
class Context { std::unique_ptr<Strategy> strategy; public: void setStrategy(std::unique_ptr<Strategy> s) { strategy = std::move(s); } void executeStrategy() { if (strategy) strategy->execute(); } };
int main() { Context c; c.setStrategy(std::make_unique<ConcreteStrategyA>()); c.executeStrategy(); return 0; }
