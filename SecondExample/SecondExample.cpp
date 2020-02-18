#include <iostream>

class creature
{
private:
	std::string title;
	double mass; //kg
protected:
	creature() : mass(0.0) {}
	creature(const creature& obj) : title(obj.title), mass(obj.mass) {}
	creature(const std::string& _title, double _mass) : title(_title), mass(_mass) {}
	// деструктор (объявлен как виртуальный)
	virtual ~creature() { std::cout << "creature deleted" << std::endl << std::endl; }
	// виртуальная функция для вывода информации об объекте 
	virtual void _print() const { std::cout << "title: " << title << ", mass: " << mass; }
public:
	// открытая функция для вывода информации об объекте
	void print() const
	{
		std::cout << typeid(*this).name() << ": (";
		// вызов виртуальной функции
		// т.к. функция _print виртуальная, вызываться она будет
		// не только из текущего класса, но и из производных,
		// в зависимости от того, для какого объекта осуществляется вызов
		_print();
		std::cout << ")" << std::endl;
	}
	double get_mass() const
	{
		return mass;
	}
};

// класс animal наследуется от класса creature
class animal : public creature
{
private:
	double speed; //m/s
public:
	animal() : creature() {}
	animal(const animal& obj) : creature(obj), speed(obj.speed) {}
	animal(const std::string& _title, double _mass, double _speed)
		: creature(_title, _mass), speed(_speed) {}
	~animal() { std::cout << "animal deleted" << std::endl; }
protected:
	// виртуальная функция _print переопределяется в производном //классе
	void _print() const
	{
		creature::_print();
		std::cout << ", speed: " << speed;
	}
public:
	double get_speed() const
	{
		return speed;
	}
};

class predator : virtual public animal
{
protected:
	predator() {}
public:
	~predator() {}
	// чисто виртуальная функция hunt будет определять 
	// посредством производных классов,
	// удастся ли хищнику поохотиться на жертву (obj)
	virtual bool hunt(const animal& obj) = 0;
	// т.к. hunt чисто виртуальная, класс predator является абстрактным
};

// класс bird наследуется от класса animal
class bird : virtual public animal
{
private:
	double topfly; //km
public:
	bird() : animal() {}
	bird(const bird& obj) : animal(obj), topfly(obj.topfly) {}
	bird(const std::string& _title, double _mass, double _speed, double _topfly)
		: animal(_title, _mass, _speed), topfly(_topfly) {}
	~bird() { std::cout << "bird deleted" << std::endl; }
protected:
	// виртуальная функция _print переопределяется в классе bird
	void _print() const
	{
		animal::_print();
		std::cout << ", topfly: " << topfly;
	}
};

// используется множественное наследование, т.к. орел – и птица, и хищник
class eagle : public bird, public predator
{
public:
	eagle() : bird() {}
	eagle(const eagle& obj)
		: bird(obj),
		// из-за виртуального наследования, для передачи параметров
		// в конструктор класса animal, его необходимо вызвать явно
		animal(obj) {}
	eagle(double _mass, double _speed, double _topfly)
		: bird("", 0, 0, _topfly),
		// аналогично
		animal("Орел", _mass, _speed) {}
	bool hunt(const animal& obj)
	{
		return obj.get_mass() < get_mass()
			&& obj.get_speed() < get_speed();
	}

};

// класс fish наследуется от класса animal
class fish : public animal
{
private:
	double maxdeep; //km
public:
	fish() : animal() {}
	fish(const fish& obj) : animal(obj), maxdeep(obj.maxdeep) {}
	fish(const std::string& _title, double _mass, double _speed, double _maxdeep)
		: animal(_title, _mass, _speed), maxdeep(_maxdeep) {}
	~fish() { std::cout << "fish deleted" << std::endl; }
protected:
	// виртуальная функция _print переопределяется в классе fish
	void _print() const
	{
		animal::_print();
		std::cout << ", maxdeep: " << maxdeep;
	}
};


int main()
{
	setlocale(0, "Rus");
	bird raven("Ворона", 0.3, 10, 0.1);
	eagle eagle1(1, 100, 1);
	fish hammerhead("Рыба-молот", 150, 5, 0.5);
	raven.print();
	hammerhead.print();
	std::cout << "Eagle vs raven: " << eagle1.hunt(raven) << std::endl;
	std::cout << "Eagle vs hammerhead: " << eagle1.hunt(hammerhead) << std::endl;
	return 0;
}
