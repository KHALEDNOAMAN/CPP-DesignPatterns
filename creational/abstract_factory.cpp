// Abstract Factory
// Use Case: Creating families of related or dependent objects without specifying their concrete classes.
#include <iostream>
#include <memory>
class Button { public: virtual void paint() = 0; virtual ~Button() = default; };
class WinButton : public Button { public: void paint() override { std::cout << "WinButton\n"; } };
class MacButton : public Button { public: void paint() override { std::cout << "MacButton\n"; } };
class GUIFactory { public: virtual std::unique_ptr<Button> createButton() = 0; virtual ~GUIFactory() = default; };
class WinFactory : public GUIFactory { public: std::unique_ptr<Button> createButton() override { return std::make_unique<WinButton>(); } };
class MacFactory : public GUIFactory { public: std::unique_ptr<Button> createButton() override { return std::make_unique<MacButton>(); } };
int main() { std::unique_ptr<GUIFactory> factory = std::make_unique<WinFactory>(); auto btn = factory->createButton(); btn->paint(); return 0; }
