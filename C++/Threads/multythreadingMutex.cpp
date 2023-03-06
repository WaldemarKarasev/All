#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>


using namespace std;

/*
* mutex
* mutex guard 
*/



mutex mtx;




void Print(char ch)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	
	//mtx.lock();
	unique_lock<mutex> ul(mtx);
	
	//lock_guard<mutex> guard(mtx);
		

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;
	
	ul.unlock();

	//mtx.unlock();
	
	this_thread::sleep_for(chrono::milliseconds(2000));
}

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






int main()
{

	SimpleTimer timer;

    thread t1(Print, '*');
	thread t2(Print, '$');

	//Print('$');
	//Print('%');
	t1.join();
	t2.join();
	
	

	return 0;;
}
