// Iterator
// Use Case: Providing a way to access the elements of an aggregate object sequentially without exposing its underlying representation.
#include <iostream>
#include <vector>
#include <memory>
class Iterator { public: virtual bool hasNext() = 0; virtual int next() = 0; virtual ~Iterator() = default; };
class ConcreteAggregate; 
class ConcreteIterator : public Iterator { ConcreteAggregate& aggregate; int index = 0; public: ConcreteIterator(ConcreteAggregate& a) : aggregate(a) {} bool hasNext() override; int next() override; };
class ConcreteAggregate { std::vector<int> items; public: void add(int i) { items.push_back(i); } int get(int index) { return items[index]; } int size() { return items.size(); } std::unique_ptr<Iterator> createIterator() { return std::make_unique<ConcreteIterator>(*this); } };
bool ConcreteIterator::hasNext() { return index < aggregate.size(); }
int ConcreteIterator::next() { return aggregate.get(index++); }
int main() { ConcreteAggregate a; a.add(1); a.add(2); auto it = a.createIterator(); while(it->hasNext()) std::cout << it->next() << " "; return 0; }
