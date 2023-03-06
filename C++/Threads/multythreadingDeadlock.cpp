#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>


using namespace std;

/*
* mutex
* mutex guard
*/



mutex mtx1;
mutex mtx2;




void Print()
{
	mtx1.lock();

	this_thread::sleep_for(chrono::milliseconds(1));

	mtx2.lock();



	for (size_t i = 0; i < 5; i++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << '#';
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;
	


	mtx2.unlock();

	mtx1.unlock();

	
}

void Print2()
{
	mtx1.lock();

	//this_thread::sleep_for(chrono::milliseconds(1));

	mtx2.lock();



	for (size_t i = 0; i < 5; i++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << '@';
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;



	mtx2.unlock();

	mtx1.unlock();


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

	thread t1(Print);
	thread t2(Print2);

	

	t1.join();
	t2.join();

		

	return 0;;
}
