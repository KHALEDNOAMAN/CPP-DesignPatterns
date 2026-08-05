// Observer
// Use Case: Defining a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.
#include <iostream>
#include <vector>
#include <memory>
class Observer { public: virtual void update() = 0; virtual ~Observer() = default; };
class Subject { std::vector<std::shared_ptr<Observer>> observers; public: void attach(std::shared_ptr<Observer> o) { observers.push_back(o); } void notify() { for (auto& o : observers) o->update(); } };
class ConcreteObserver : public Observer { public: void update() override { std::cout << "ConcreteObserver updated\n"; } };
int main() { Subject s; auto o = std::make_shared<ConcreteObserver>(); s.attach(o); s.notify(); return 0; }
