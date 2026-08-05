// Smart Pointers
// Use Case: Automatic memory management to prevent memory leaks.
#include <iostream>
#include <memory>
class Resource { public: Resource() { std::cout << "Acquired\n"; } ~Resource() { std::cout << "Released\n"; } void use() { std::cout << "Using\n"; } };
int main() { std::unique_ptr<Resource> ptr = std::make_unique<Resource>(); ptr->use(); return 0; }
