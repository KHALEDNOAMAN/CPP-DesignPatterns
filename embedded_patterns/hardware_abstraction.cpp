// Hardware Abstraction Layer (HAL)
// Use Case: Isolating higher-level code from hardware specifics.
#include <iostream>
class IGPIO { public: virtual void setHigh() = 0; virtual void setLow() = 0; virtual ~IGPIO() = default; };
class STM32GPIO : public IGPIO { public: void setHigh() override { std::cout << "STM32 High\n"; } void setLow() override { std::cout << "STM32 Low\n"; } };
int main() { STM32GPIO gpio; gpio.setHigh(); return 0; }
