// Object Pool Pattern
// Reuse expensive objects instead of creating new ones
#include <queue>
#include <memory>
using namespace std;

template<class T>
class ObjectPool {
    queue<shared_ptr<T>> pool;
public:
    shared_ptr<T> acquire() {
        if (pool.empty()) return make_shared<T>();
        auto obj = pool.front(); pool.pop();
        return obj;
    }
    void release(shared_ptr<T> obj) { pool.push(obj); }
};