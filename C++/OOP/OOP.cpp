#include <iostream>
#include <string>

using namespace std;

class Human
{
private:
	
	int age;
	int weight;
	string name;

public:

	Human()
	{
		age = 0;
		weight = 0;
		name = "";
	}
	
	Human(int age, int weight, string name)
	{
		this->age = age;
		this->weight = weight;
		this->name = name;
	}

	void SetHuman(int age, int weight, string name)
	{
		this->age = age;
		this->weight = weight;
		this->name = name;
	}

	int GetAge()
	{
		return age;
	}

	string GetName()
	{
		return name;
	}

	void Print()
	{
		cout << "name: " << name << "\tweight: " << weight << "\tage: " << age << endl;
	}

protected:
};

class MyClass
{
private:

	int* data;
	int size;

public:

	MyClass(int size)
	{
		this->size = size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		cout << "Constructor " << this << endl;
	}
	
	MyClass(const MyClass& other)
	{
		this->size = other.size;	 
		this->data = new int[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "Copy_Constructor" << this << endl;

	}

	MyClass& operator = (const MyClass& other)
	{
		cout << "Operator =" << this << endl;

		this->size = other.size;

		if (this->data != nullptr)
		{
			delete[] this->data;
		}

		this->data = new int[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "Copy_Constructor" << this << endl;

		return *this;
	}



	~MyClass()
	{
		cout << "Destructor " << this << endl;
		delete[] data;
	}

};

void Foo(MyClass value)
{
	cout << "FOO" << endl;
}

MyClass Foo2()
{
	cout << "FOO2" << endl;
	MyClass temp(2);

	return temp;
}

class Test;
class Point
{
private:

	int x;
	int y;

public:
	
	Point()
	{
		x = 0;
		y = 0;
		cout << this << " Constructor" << endl;
	}

	Point(int valueX, int valueY)
	{
		x = valueX;
		y = valueY;
		cout << this << " Constructor" << endl;
	}

	void SetX(int x)
	{
		this->x = x;
	}

	void SetY(int y)
	{
		this->y = y;
	}

	int GetX()
	{
		return x;
	}

	int GetY()
	{
		return y;
	}

	void Print()
	{
		cout << "x = " << x << ", y = " << y << endl;
	}

	bool operator == (const Point& other)
	{
		return (this->x == other.x && this->y == other.y);
	}

	bool operator != (const Point& other)
	{
		return !(this->x == other.x && this->y == other.y);
	}

	bool operator > (const Point& other)
	{
		return (this->x > other.x && this->y > other.y);
	}

	bool operator < (const Point& other)
	{
		return this->x < other.x && this->y < other.y;
	}

	bool operator >= (const Point& other)
	{
		return this->x >= other.x&& this->y >= other.y;
	}

	bool operator <= (const Point& other)
	{
		return this->x <= other.x&& this->y <= other.y;
	}

	Point operator +(const Point& other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;

		return temp;
	}

	Point operator -(const Point& other)
	{
		Point temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;

		return temp;
	}

	Point operator *(const Point& other)
	{
		Point temp;
		temp.x = this->x * other.x;
		temp.y = this->y * other.y;

		return temp;
	}

	Point operator /(const Point& other)
	{
		Point temp;
		temp.x = this->x / other.x;
		temp.y = this->y / other.y;

		return temp;
	}

	Point& operator ++()
	{
		this->x++;
		this->y++;

		return *this;
	}

	Point& operator ++(int value)
	{
		Point temp(*this);
		this->x++;
		this->y =+1;

		return temp;
	}

	Point& operator --()
	{
		this->x--;
		this->y--;

		return *this;
	}

	Point& operator --(int value)
	{
		Point temp(*this);
		this->x--;
		this->y = -1;

		return temp;
	}

	friend void ChangeX(Point& value1, Test& value2);
};

class Test
{
public:

	int& operator[](int index)
	{
		return arr[index];
	}

	friend void ChangeX(Point& value1, Test& value2);
private:
	int arr[5]{ 1,2,3,4,5 };

};

void ChangeX(Point& value1, Test& value2)
{
	value1.x = -1;
	value2.arr[1] = -1;
}

class TestClass
{
public:
	
	void Printmessage();

private:

};

void TestClass::Printmessage()
{
	cout << "Hello" << endl;
}

int main()
{
	TestClass a;
	a.Printmessage();
	
	return 0;
}