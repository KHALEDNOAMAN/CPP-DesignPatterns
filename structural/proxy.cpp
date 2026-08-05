// Proxy
// Use Case: Providing a surrogate or placeholder for another object to control access to it.
#include <iostream>
#include <memory>
class Subject { public: virtual void request() = 0; virtual ~Subject() = default; };
class RealSubject : public Subject { public: void request() override { std::cout << "RealSubject request\n"; } };
class Proxy : public Subject { std::unique_ptr<RealSubject> realSubject; public: void request() override { if (!realSubject) realSubject = std::make_unique<RealSubject>(); realSubject->request(); } };
int main() { Proxy p; p.request(); return 0; }
