// Memento
// Use Case: Without violating encapsulation, capturing and externalizing an object's internal state so that the object can be restored to this state later.
#include <iostream>
#include <string>
class Memento { std::string state; public: Memento(std::string s) : state(s) {} std::string getState() const { return state; } };
class Originator { std::string state; public: void setState(std::string s) { state = s; std::cout << "State: " << state << "\n"; } Memento save() { return Memento(state); } void restore(const Memento& m) { state = m.getState(); std::cout << "Restored: " << state << "\n"; } };
int main() { Originator o; o.setState("State1"); Memento m = o.save(); o.setState("State2"); o.restore(m); return 0; }
