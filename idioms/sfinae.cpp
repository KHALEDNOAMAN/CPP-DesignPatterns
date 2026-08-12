#include <iostream>
#include <type_traits>
template <typename T> void foo(T t, typename std::enable_if<std::is_integral<T>::value>::type* = 0) {}
int main() { return 0; }