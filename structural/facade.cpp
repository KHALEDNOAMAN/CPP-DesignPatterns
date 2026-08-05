// Facade
// Use Case: Providing a unified interface to a set of interfaces in a subsystem.
#include <iostream>
class SubsystemA { public: void operationA() { std::cout << "SubsystemA\n"; } };
class SubsystemB { public: void operationB() { std::cout << "SubsystemB\n"; } };
class Facade { SubsystemA a; SubsystemB b; public: void operation() { a.operationA(); b.operationB(); } };
int main() { Facade f; f.operation(); return 0; }
