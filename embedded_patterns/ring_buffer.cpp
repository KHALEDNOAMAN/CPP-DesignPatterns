// Ring Buffer
// Use Case: Storing continuous streams of data, often used in UART/SPI communications.
#include <iostream>
#include <array>
class RingBuffer { std::array<int, 5> buffer; size_t head = 0, tail = 0; bool full = false; public: void push(int val) { buffer[head] = val; if (full) tail = (tail + 1) % buffer.size(); head = (head + 1) % buffer.size(); full = head == tail; } int pop() { if (empty()) return -1; int val = buffer[tail]; full = false; tail = (tail + 1) % buffer.size(); return val; } bool empty() const { return (!full && (head == tail)); } };
int main() { RingBuffer rb; rb.push(1); rb.push(2); std::cout << rb.pop() << "\n"; return 0; }
