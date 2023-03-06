#include <iostream>
#include <typeinfo>

using namespace std;

class Point
{
public:
	Point()
	{
		x = y = z = 0;
	}
	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
private:
	int x;
	int y;
	int z;
};



//шаблон класса
template<class T1>
class TypeSize
{
public:
	TypeSize(T1 value1)
	{
		this->value1 = value1;
		
	}

	void DataTypeSize()
	{
		cout << sizeof(value1) << endl;

	}

protected:
	T1 value1;

};


template<class T1>
class TypeInfo : public TypeSize<T1>
{
public:
	TypeInfo(T1 value1) : TypeSize<T1>::TypeSize (value1) {}
	void ShowTypeName()
	{
		cout << "typeid:" << typeid(this->value1).name() << endl ;
	}
	
};



//специализацция шаблонов класса
template<typename T>
class Printer
{
public:
	void Print(T value)
	{
		cout << value << endl;
	}
};

template<>
class Printer<string>
{
public:
	void Print(string value)
	{
		cout << "___" << value << "___" << endl;
	}
};


int main()
{
	Printer<int> a;
	a.Print(6);


	
	return 0;
}	
