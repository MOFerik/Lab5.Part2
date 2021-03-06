﻿#include <iostream>

using namespace std;

class Base
{
public: int baseCheck = 0;
	Base() // Конструкторы базового класса
	{
		cout << "Base-class object created. Constructor: Base()\n";
	};

	Base(Base* obj) 
	{
		cout << "Base-class object created. Constructor: Base(Base* obj)\n";
	};

	Base(Base& obj) 
	{
		cout << "Base-class object created. Constructor: Base(Base& obj)\n";
	};

	virtual string classname() // Виртуальный метод получения названия класса объекта
	{
		return "Base";
	}

	virtual bool isA(string clsname) // Виртуальный метод проверки принадлежности объекта классу
	{
		if (classname() == clsname) 
		{
			cout << "Object's class is " << clsname << ".\n";
			return true;
		}
		else {
			cout << "Object's class is not " << clsname << ".\n";
			return false;
		}
	}

	~Base() // Деструктор базового класса
	{
		cout << "Base-class object destroyed.\n";
	};
};

class Desc : public Base
{
	public:
	Desc() // Конструкторы класса-наследника
	{
		cout << "Desc-class object created. Contructor: Desc()\n";
	};

	Desc(Desc* obj)
	{
		cout << "Desc-class object created. Contructor: Desc(Desc* obj)\n";
	};

	Desc(Desc& obj)
	{
		cout << "Desc-class object created. Contructor: Desc(Desc& obj)\n";
	};

	string classname() // Перекрытый метод получения названия класса
	{
		return "Desc";
	}

	bool isA(string clsname) // Перекрытый метод проверки принадлежности обхекта классу
	{
		if (classname() == clsname)
		{
			cout << "Object's class is " << clsname << ".\n";
			return true;
		}
		else {
			cout << "Object's class is not " << clsname << ".\n";
			return false;
		}
	}

	~Desc() // Деструктор наследника
	{
		cout << "Desc-class object destroyed.\n";
	};
};

void func1(Base obj)  // Копирующая функция
{
	obj.baseCheck++;
	cout << "Function func1(Base obj) called. obj.baseCheck value: " << obj.baseCheck << "\n";
};

void func2(Base* obj) // Функция принимающая ссылку
{
	obj->baseCheck++;
	cout << "Function func2(Base* obj) called. obj->baseCheck value: " << obj->baseCheck << "\n";
};

void func3(Base& obj) // Функция принимающая адрес
{
	obj.baseCheck++;
	cout << "Function func3(Base& obj) called. obj.baseCheck value: " << obj.baseCheck << "\n";
};

void base1Ops() // Создание объекта класса Base и передача его параметром в фукции
{
	cout << "Creating Base-class object base1, via constructor Base():\n";
	Base base1;
	cout << "\nCalling func1(base1):\n";
	func1(base1);
	cout << "\nCalling func2(&base1):\n";
	func2(&base1);
	cout << "\nCalling func3(base1):\n";
	func3(base1);
	cout << "\nDestroying base1:\n";
}

void desc1Ops() // Создание объекта класса Desc и передача его параметром в фукции
{
	cout << "\n\nCreating Desc-class object desc1, via constructor Desc():\n";
	Desc desc1;
	cout << "\nCalling func1(desc1):\n";
	func1(desc1);
	cout << "\nCalling func2(&desc1):\n";
	func2(&desc1);
	cout << "\nCalling func3(desc1):\n";
	func3(desc1);
	cout << "\nDestroying desc1:\n";
}

void funcDynamicCast() // Приведение static_cast
{
	cout << "\n\nCreating Desc-class Object desc2:\n";
	Desc* desc2 = new Desc;
	cout << "\nCreating Base-class Object base2 and dynamicly cassting it to Desc-class type:\n";
	Base* base2 = new Base;
	base2 = dynamic_cast<Base*>(desc2);

	cout << "\nChecking base2's type using isA('Desc'): \n";
	base2->isA("Desc");
}

void funcManualCast() // Приведение вручную
{
	cout << "\n\nCreating Desc-class Object desc3:\n";
	Desc* desc3 = new Desc;
	cout << "\nCreating Base-class Object base3 and manually cassting it to Desc-class type:\n";
	Base* base3 = new Base;
	base3 = ((Base*)(desc3));

	cout << "\nChecking base3's type using isA('Desc'): \n";
	base3->isA("Desc");
}

int main()
{
	base1Ops();

	desc1Ops();

	funcDynamicCast();

	funcManualCast();
}
