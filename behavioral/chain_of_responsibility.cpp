// Chain of Responsibility
// Use Case: Avoiding coupling the sender of a request to its receiver by giving more than one object a chance to handle the request.
#include <iostream>
#include <memory>
class Handler { protected: std::shared_ptr<Handler> next; public: void setNext(std::shared_ptr<Handler> n) { next = n; } virtual void handleRequest(int request) { if (next) next->handleRequest(request); } virtual ~Handler() = default; };
class ConcreteHandler1 : public Handler { public: void handleRequest(int request) override { if (request < 10) std::cout << "Handler1 handled " << request << "\n"; else Handler::handleRequest(request); } };
class ConcreteHandler2 : public Handler { public: void handleRequest(int request) override { if (request >= 10) std::cout << "Handler2 handled " << request << "\n"; else Handler::handleRequest(request); } };
int main() { auto h1 = std::make_shared<ConcreteHandler1>(); auto h2 = std::make_shared<ConcreteHandler2>(); h1->setNext(h2); h1->handleRequest(5); h1->handleRequest(15); return 0; }
