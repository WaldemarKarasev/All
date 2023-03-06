#include <iostream>

using namespace std;
/*
* Полиморфизм
* Виртуальные функции
* virtual
* override 
*/

/*
* Абстрактные классы
* Чисто виртуальные функции
*/


class Weapon
{
public:

	virtual void Shoot() = 0;

	void Foo()
	{
		cout << "Foo()" << endl;
	}

};




class Gun : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BANG!" << endl;
	}

};

class SubMachineGun : public Gun
{
public:
	void Shoot() override
	{
		cout << "BANG! BANG! BANG!" << endl;
	}
};

class Bazooka : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BADABUM!!!" << endl;
	}

};

class Knife : public Weapon
{
public:
	void Shoot() override
	{
		cout << "VJUH!!!" << endl;
	}
};


class Player
{
public:
	void Shoot(Weapon* gun)
	{
		gun->Shoot();
	}

};

int main()
{
	Gun gun;
	SubMachineGun machinegun;
	Knife knife;

	// Полиморфизм  //
	Weapon* weapon = &knife;

	Player man;
	man.Shoot(weapon);
	//				//
	knife.Foo();

}