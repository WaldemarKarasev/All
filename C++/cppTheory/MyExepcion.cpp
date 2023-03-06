#include <iostream>

using namespace std;


class MyException : public exception
{
public:
	MyException(const char* msg, int dataState):exception(msg)
	{
		this->dataState = dataState;
	}
	
	int getDataState() { return dataState; }

private:
	int dataState;

};

void Foo(int value)
{
	if (value < 0)
	{
		throw exception("Number less than 0");
	}

	if (value == 1)
	{
		throw MyException("Number is 1", value);
	}

	cout << "Variable = " << value << endl;
}


int main()
{
    
	try
	{
		Foo(-1);
	}
	catch (MyException &ex)
	{
		cout << "We caught bock 1" << endl;
		//cout << ex.what() << endl;
		cout << "Data state is " << ex.getDataState() << endl;
	}
	catch (exception& ex)
	{
		cout << "We caught bock 2" << endl;
		cout << ex.what() << endl;
	}

    return 0;
}
