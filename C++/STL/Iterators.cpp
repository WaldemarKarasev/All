#include <iostream>
#include <vector>

using namespace std;



int main()
{
	vector<int> myVector = { 1,2,3,4,5 };

	vector<int>::iterator it = myVector.begin();
	cout << *it << endl;
	advance(it, 4);
	cout << *it << endl;

	cout << typeid(it).name() << endl;

	for (vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
	{
		cout << *i << " ";
	}

	cout << endl;

	for (vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
	{
		cout << *i << " ";
	}

	cout << endl;

	for (vector<int>::const_iterator i = myVector.cbegin(); i < myVector.cend(); i++)
	{
		cout << *i << " ";
	}

	cout << endl;

	for (vector<int>::reverse_iterator i = myVector.rbegin(); i < myVector.rend(); i++)
	{
		cout << *i << " ";
	}

	cout << endl;





	cout << "isert" << endl;

	myVector.insert(it + 1, 999);
	
	for (vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
	{
		cout << *i << " ";
	}

	cout << endl;

	cout << "erase" << endl;
	vector<int>::iterator itErase = myVector.begin();
	myVector.erase(itErase, itErase + 2);

	for (vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
	{
		cout << *i << " ";
	}

	return 0;
}
