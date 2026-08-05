// Composite
// Use Case: Composing objects into tree structures to represent part-whole hierarchies.
#include <iostream>
#include <vector>
#include <memory>
class Component { public: virtual void operation() = 0; virtual ~Component() = default; };
class Leaf : public Component { public: void operation() override { std::cout << "Leaf\n"; } };
class Composite : public Component { std::vector<std::shared_ptr<Component>> children; public: void add(std::shared_ptr<Component> c) { children.push_back(c); } void operation() override { std::cout << "Composite\n"; for (auto& c : children) c->operation(); } };
int main() { auto root = std::make_shared<Composite>(); root->add(std::make_shared<Leaf>()); root->add(std::make_shared<Leaf>()); root->operation(); return 0; }
