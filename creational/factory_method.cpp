// Factory Method
// Use Case: When a class cannot anticipate the class of objects it must create.
#include <iostream>
#include <memory>
class Shape { public: virtual void draw() = 0; virtual ~Shape() = default; };
class Circle : public Shape { public: void draw() override { std::cout << "Circle\n"; } };
class ShapeFactory { public: static std::unique_ptr<Shape> createShape() { return std::make_unique<Circle>(); } };
int main() { auto s = ShapeFactory::createShape(); s->draw(); return 0; }
