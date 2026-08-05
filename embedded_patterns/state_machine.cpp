// Embedded State Machine
// Use Case: Managing complex states in resource-constrained systems without dynamic memory allocation.
#include <iostream>
enum class State { IDLE, RUNNING, STOPPED };
class StateMachine { State state = State::IDLE; public: void trigger() { switch(state) { case State::IDLE: state = State::RUNNING; std::cout << "Run\n"; break; case State::RUNNING: state = State::STOPPED; std::cout << "Stop\n"; break; case State::STOPPED: state = State::IDLE; std::cout << "Idle\n"; break; } } };
int main() { StateMachine sm; sm.trigger(); sm.trigger(); return 0; }
