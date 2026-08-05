// Command
// Use Case: Encapsulating a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.
#include <iostream>
#include <memory>
class Command { public: virtual void execute() = 0; virtual ~Command() = default; };
class Receiver { public: void action() { std::cout << "Receiver action\n"; } };
class ConcreteCommand : public Command { Receiver& receiver; public: ConcreteCommand(Receiver& r) : receiver(r) {} void execute() override { receiver.action(); } };
class Invoker { std::unique_ptr<Command> command; public: void setCommand(std::unique_ptr<Command> c) { command = std::move(c); } void invoke() { if (command) command->execute(); } };
int main() { Receiver r; auto c = std::make_unique<ConcreteCommand>(r); Invoker i; i.setCommand(std::move(c)); i.invoke(); return 0; }
