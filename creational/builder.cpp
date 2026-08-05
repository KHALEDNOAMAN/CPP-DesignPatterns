// Builder
// Use Case: Constructing complex objects step by step.
#include <iostream>
#include <string>
class Pizza { public: void setDough(const std::string& d) { dough = d; } void setSauce(const std::string& s) { sauce = s; } void setTopping(const std::string& t) { topping = t; } void show() const { std::cout << dough << " " << sauce << " " << topping << "\n"; } private: std::string dough, sauce, topping; };
class PizzaBuilder { protected: Pizza pizza; public: virtual ~PizzaBuilder() = default; virtual void buildDough() = 0; virtual void buildSauce() = 0; virtual void buildTopping() = 0; Pizza getPizza() { return pizza; } };
class HawaiianPizzaBuilder : public PizzaBuilder { public: void buildDough() override { pizza.setDough("cross"); } void buildSauce() override { pizza.setSauce("mild"); } void buildTopping() override { pizza.setTopping("ham and pineapple"); } };
int main() { HawaiianPizzaBuilder builder; builder.buildDough(); builder.buildSauce(); builder.buildTopping(); builder.getPizza().show(); return 0; }
