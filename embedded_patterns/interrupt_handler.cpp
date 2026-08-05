// Interrupt Service Routine (ISR) Pattern
// Use Case: Decoupling hardware interrupts from application logic.
#include <iostream>
#include <functional>
class InterruptManager { std::function<void()> isr; public: void attach(std::function<void()> f) { isr = f; } void trigger() { if (isr) isr(); } };
int main() { InterruptManager mgr; mgr.attach([](){ std::cout << "ISR fired\n"; }); mgr.trigger(); return 0; }
