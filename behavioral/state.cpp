// State
// Use Case: Allowing an object to alter its behavior when its internal state changes. The object will appear to change its class.
#include <iostream>
#include <memory>
class Context;
class State { public: virtual void handle(Context& context) = 0; virtual ~State() = default; };
class Context { std::unique_ptr<State> state; public: void setState(std::unique_ptr<State> s) { state = std::move(s); } void request() { if (state) state->handle(*this); } };
class ConcreteStateA : public State { public: void handle(Context& context) override { std::cout << "ConcreteStateA\n"; } };
int main() { Context c; c.setState(std::make_unique<ConcreteStateA>()); c.request(); return 0; }
