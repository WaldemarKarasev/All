#include <iostream>
#include <thread>
#include <chrono>

using  namespace std;

class SimpleTimer
{
public:
	SimpleTimer()
	{
		start = chrono::high_resolution_clock::now();
	}
	~SimpleTimer()
	{
		end = chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		cout << "Duration" << duration.count() << "s" << endl;
	}

private:
	std::chrono::time_point < std::chrono::steady_clock> start, end;
};
 

int Sum(int a, int b)
{
	SimpleTimer st;


	this_thread::sleep_for(chrono::milliseconds(2000));

	cout << "ID thread = " << this_thread::get_id() << "\t======= " << "Sum STARTED\t=======" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));

	cout << "ID thread = " << this_thread::get_id() << "\t=======	" << "Sum STOPPED\t=======" << endl;

	return a + b;
}

void DoWork(int& a)
{
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "ID thread = " << this_thread::get_id() << "\t=======\t" << "DoWork STARTED\t=======" << endl;
	this_thread::sleep_for(chrono::milliseconds(4000));

	a = a * 2;

	//this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "ID thread = " << this_thread::get_id() << "\t=======\t" << "DoWork STOPPED\t=======" << endl;
}


void Foo()
{
	SimpleTimer st;
	for (size_t i = 0; i < 500; i++)
	{
		cout << i << endl;
	}
}


int main()
{
	/*
	thread th(DoWork);

	//th.detach();


	cout << "START MAIN" << endl;

	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID thread = " << this_thread::get_id() << "\tmain "<< i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	th.join();
	cout << "END MAIN" << endl;
	*/

	/*thread th(DoWork, 5, 6);

	for (size_t i = 0; true; i++)
	{
		cout << "ID thread = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	th.join();*/

	//SimpleTimer st;
	
	Foo();
	//int result;
	//thread th([&result]() {result = Sum(2, 5); });
	

	//auto f = [&result]() {result = Sum(2, 5); };

	for (size_t i = 0; i <= 10; i++)
	{
		cout << "ID thread = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	
	//th.join();
	//cout << "Sum results = " << result << endl;
	


	return 0;
}
