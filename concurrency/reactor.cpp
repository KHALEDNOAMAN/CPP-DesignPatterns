// Reactor Pattern - Event-driven I/O multiplexing
#include <functional>
#include <map>
using namespace std;
class Reactor {
    map<int, function<void()>> handlers;
public:
    void registerHandler(int fd, function<void()> handler) {
        handlers[fd] = handler;
    }
    void removeHandler(int fd) { handlers.erase(fd); }
    void handleEvents() {
        for (auto& [fd, handler] : handlers) handler();
    }
};