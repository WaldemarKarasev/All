#include <iostream>
#include <cmath>

using namespace std;

void fun(int a)
{
	cout << a << "\n";
}

void fun1(int& a) 
{
	a = a + 1;
	cout << a << "\n";
}

void fun2(const int& a)
{
	cout << 5 * a << "\n";
}

void getSinCos(double degrees, double& sinOut, double& cosOut)
{
	const double pi = 3.14159265358979323846;
	double radians = degrees * pi / 180.0;
	sinOut = sin(radians);
	cosOut = cos(radians);
}

void boo(int* ptr) 
{
	*ptr = 7;
}

void printArray(const int* arr, int length) 
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void setToNull(int*& tempPtr)
{
	tempPtr = nullptr;
}

int fun3(int a)
{
	return a;
}

int main()
{
	fun(1);

	int value = 2;
	cout << value << "\n";
	fun1(value);
	cout << value << "\n";
	fun2(value);

	double sin(0.0);
	double cos(0.0);

	getSinCos(30, sin, cos);

	cout << sin << "\n";
	cout << cos << "\n";

	int value1 = 5;
	cout << value1 << "\n";
	boo(&value1);
	cout << value1 << "\n";

	int array[5]{ 0,1,2,3,4 };
	printArray(array, 5);


	int six = 6;
	int* ptr = &six;
	cout << *ptr;

	setToNull(ptr);
 
	if (ptr)
		cout << *ptr;
	else
		cout << " ptr is null\n";

	cout << fun << "\n";
	cout << reinterpret_cast<void*>(fun) << "\n";

	int (*fcnPtr)(int) = fun3;
	fun3(5);
	(*fcnPtr)(9);
	fcnPtr(8);
	cout << "fun3 = " << fun3 << " fcnPtr = " << fcnPtr;
	return 0;
}
