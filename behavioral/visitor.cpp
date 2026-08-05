// Visitor
// Use Case: Representing an operation to be performed on the elements of an object structure.
#include <iostream>
class ConcreteElementA; class ConcreteElementB;
class Visitor { public: virtual void visit(ConcreteElementA& a) = 0; virtual void visit(ConcreteElementB& b) = 0; virtual ~Visitor() = default; };
class Element { public: virtual void accept(Visitor& v) = 0; virtual ~Element() = default; };
class ConcreteElementA : public Element { public: void accept(Visitor& v) override { v.visit(*this); } void operationA() { std::cout << "ElementA\n"; } };
class ConcreteElementB : public Element { public: void accept(Visitor& v) override { v.visit(*this); } void operationB() { std::cout << "ElementB\n"; } };
class ConcreteVisitor : public Visitor { public: void visit(ConcreteElementA& a) override { a.operationA(); } void visit(ConcreteElementB& b) override { b.operationB(); } };
int main() { ConcreteElementA a; ConcreteElementB b; ConcreteVisitor v; a.accept(v); b.accept(v); return 0; }
