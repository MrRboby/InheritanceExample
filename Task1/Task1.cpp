#include <iostream>

class B1 {
public:
	B1() { std::cout << "object of " << typeid(*this).name() << " was created" << std::endl; }
	~B1() { std::cout << "object of " << typeid(*this).name() << " was destroyed" << std::endl; }
};
class B2 {
public:
	B2() { std::cout << "object of " << typeid(*this).name() << " was created" << std::endl; }
	~B2() { std::cout << "object of " << typeid(*this).name() << " was destroyed" << std::endl; }
};
class D1 : public B1, private B2 {
public:
	D1() { std::cout << "object of " << typeid(*this).name() << " was created" << std::endl; }
	~D1() { std::cout << "object of " << typeid(*this).name() << " was destroyed" << std::endl; }
};
class D2 : private D1 {
public:
	D2() { std::cout << "object of " << typeid(*this).name() << " was created" << std::endl; }
	~D2() { std::cout << "object of " << typeid(*this).name() << " was destroyed" << std::endl; }
};
class B3 {
public:
	B3() { std::cout << "object of " << typeid(*this).name() << " was created" << std::endl; }
	~B3() { std::cout << "object of " << typeid(*this).name() << " was destroyed" << std::endl; }
};
class D3 : public D2, private B3 {
public:
	D3() { std::cout << "object of " << typeid(*this).name() << " was created" << std::endl; }
	~D3() { std::cout << "object of " << typeid(*this).name() << " was destroyed" << std::endl; }
};

int main() {
	D3 temp = D3();
	return 0;
}