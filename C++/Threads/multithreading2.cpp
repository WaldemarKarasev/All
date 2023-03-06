#include <iostream>
#include <thread>
#include <chrono>

using  namespace std;


class MyClass
{
public:
	
	void DoWork()
	{
		this_thread::sleep_for(chrono::milliseconds(2000));

		cout << "ID thread = " << this_thread::get_id() << "\t=======\tDoWork STARTED\t=======" << endl;

		this_thread::sleep_for(chrono::milliseconds(4000));

		cout << "ID thread = " << this_thread::get_id() << "\t=======\tDoWork STOPPED\t=======" << endl;
	}

	void DoWork2(int a)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));

		cout << "ID thread = " << this_thread::get_id() << "\t=======\tDoWork2 STARTED\t=======" << endl;

		this_thread::sleep_for(chrono::milliseconds(4000));

		cout << "DoWork2 parameter value\t" << a << endl;

		cout << "ID thread = " << this_thread::get_id() << "\t=======\tDoWork2 STOPPED\t=======" << endl;

	}

	int Sum(int a, int b)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));

		cout << "ID thread = " << this_thread::get_id() << "\t=======\tSum STARTED\t=======" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));

		cout << "ID thread = " << this_thread::get_id() << "\t=======\tSum STOPPED\t=======" << endl;

		return a + b;
	}

private:

};


int main()
{
	MyClass m;

	/*thread t([&]()
		{
			return m.Sum(100,100);
		});*/

	//thread t(&MyClass::DoWork, &m);

	//thread t(&MyClass::DoWork2, &m, 11111);


	for (size_t i = 1; i <= 10; i++)
	{
		cout << "ID thread = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	t.join();
	

	return 0;
}
