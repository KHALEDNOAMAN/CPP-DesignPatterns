// Meyers Singleton
// Use Case: When exactly one instance of a class is needed to coordinate actions.
#include <iostream>
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    void doSomething() { std::cout << "Doing something\n"; }
private:
    Singleton() = default;
    ~Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};
int main() { Singleton::getInstance().doSomething(); return 0; }
