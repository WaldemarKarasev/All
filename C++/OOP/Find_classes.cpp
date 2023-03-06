#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

class Person
{
public:
	Person(string name, int score)
	{
		this->name = name;
		this->score = score;
	}

	bool operator()(const Person& p)
	{
		return p.score > 180;
	}

	string name;
	int score;
};

class Point
{
public:

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int x;
	int y;
};

void Foo(int a)
{
	cout << a << endl;
}



class IAction
{
public:
	virtual void Action() = 0;
};

class CatAction : public IAction
{
	virtual void Action() override
	{
		cout << "pet the cat" << endl;
	}
};


class DogAction : public IAction
{
	virtual void Action() override
	{
		cout << "walk the cat" << endl;
	}
};


class TeaAction : public IAction
{
	virtual void Action() override
	{
		cout << "to drink tea" << endl;
	}
};

class SleepAction : public IAction
{
	virtual void Action() override
	{
		cout << "sleep" << endl;
	}
};


int main()
{

	/*
	* STL std;;random_shuffle
	*/

	srand(time(NULL));

	IAction* arr[] =
	{
		new CatAction(),
		new DogAction(),
		new TeaAction(),
		new SleepAction()
	};
	
	//random_shuffle(begin(arr), end(arr));

	for (auto &element : arr)
	{
		element->Action();
	}


	/*
	* STL std::unique std::unique_copy
	*/
	/*
	vector<int> v = { 1,1,1,1,1,1,1,11,1111,3,4,4,5,5,5,2,2,2 };
	
	vector<int> v2;

	auto result = unique(begin(v), end(v));

	unique_copy(begin(v), end(v), back_inserter(v2));

	for_each(begin(v2), end(v2), [](int a) {cout << a << " "; });
	*/

	/*
	* STL for_each
	*/
	/*
	int arr[] = { 1,2,34,12,54,221 };

	//for_each(begin(arr), end(arr), Foo);

	for (auto a : arr)
	{
		Foo(a);
	}
	for_each(begin(arr), end(arr), [](int a)
		{
			cout << a << endl;
		});
	*/


	/*
	* STL equal predicate
	*/
	/*
	vector<Point> arr
	{
		Point(1,2),
		Point(3,4),
		Point(5,6),
	};

	vector<Point> arr2
	{
		Point(1,2),
		Point(3,4),
		Point(5,6),
	};

	bool result = equal(begin(arr), end(arr), begin(arr2), end(arr2), [](const Point& p1, const Point& p2)
		{
			return p1.x == p2.x && p1.y == p2.y;
		});

	cout << result << endl;
	*/

	/*
	* STL equal
	*/
	/*
	int arr1[] = { 2, 12, 0, 33, 20, 1 }; 
	//int arr2[] = { 2, 12, 9, 33, 20, 1 };
	vector<int> arr2 = { 2, 12, 9, 3, 20, 1 };

	//bool result = equal(begin(arr1), end(arr1), begin(arr2));
	//bool result = equal(begin(arr1), end(arr1), begin(arr2), end(arr2));

	auto result = mismatch(begin(arr1), end(arr1), begin(arr2), end(arr2));
	if (result.first==end(arr1) && result.second == end(arr2))
	{
		cout << "+" << endl;
	}
	else
	{
		cout << "-" << endl;
		cout << *result.first << endl;
		cout << *result.second << endl;

	}
	//cout << "RESULT: " << result << endl;
	*/


	/*
	* STL accumulate <numeric>
	*/
	/*
	vector<int> v = { 3,6,4 };
	
	/*begin();
	end();
	
	auto result = accumulate(begin(v), end(v), 0);
	auto result = accumulate(begin(v), end(v), 1, [](int a, int b) 
		{
			return a * b;
		});

	auto result = accumulate(begin(v), end(v), 0, [](int a, int b)
		{
			if (b % 2 == 0)
			{
				return a + b;
			}
			else
			{
				return a;
			}
		});

	
	auto result = accumulate(next(begin(v)), end(v), to_string(v[0]), [](string a, int b)
		{
			return a + "-" + to_string(b);
		});

	cout << "RESULT: " << result << endl;*/
	

	/*
	* STL max_element, min_element
	*/
	/*
	//vector<int> v = { 10 , 1, -55, 11, 29, -5, 73 };

	//list<int> lst = { 4, 5, 66, 55, 10, -3, 17 };

	const int SIZE = 5;
	int arr[SIZE] = { 1,2,2,3,5 };


	auto result = max_element(arr, arr+SIZE);

	cout << *result <<  endl;
	

	//vector<int> v = { 10 , 1, -55, 11, 29, -5, 73 };

	//list<int> lst = { 4, 5, 66, 55, 10, -3, 17 };

	const int SIZE = 5;
	int arr[SIZE] = { 1,2,2,3,5 };

	//auto result = min_element(arr, arr + SIZE);

	//cout << *result << endl;

	auto result = minmax_element(arr, arr + SIZE);

	cout << "min:\t" << *result.first << "\tmax:\t" << *result.second << endl;
	*/


	/*
	* STL remove, remove_if
	*/
	/*vector<int> v = { 1,3,5,63,2,1,3,6 };
	
	auto result = remove(v.begin(), v.end(), 1);

	v.erase(result, v.end());
	for (auto el : v)
	{
		cout << el << endl;
	}


	vector<Person> people
	{
		Person("name1", 100),
		Person("name2", 632),
		Person("name7", 200),
		Person("name8", 593),
		Person("name1", 293),
		Person("name7", 170),
		Person("name3", 195),
		Person("name4", 200),
		Person("name9", 300),

	};
	
	people.erase(remove_if(people.begin(), people.end(), [](const Person& p)
		{
			return p.score < 150;
		}), people.end());

	cout << "Total elements:\t" << people.size() << endl;

	for (auto element : people)
	{
		cout << "Name:\t" << element.name << "\tscore:\t" << element.score << endl;
	}
	


	string str = "Text with   multiple  spaces";

	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	cout << str;
	*/


	/*
	* STL copy, copy_if + sortt
	*/
	/*
	vector<Person> result;
	//copy(people.begin(), people.end(), back_inserter(result));
	copy_if(people.begin(), people.end(), back_inserter(result), [](const Person &p)
		{
			return p.score > 180;
		});

	sort(result.begin(), result.end(), [](const Person &p1, const Person &p2)
		{
			return p1.score > p2.score;
		});

	cout << "Total elements:\t" << result.size() << endl;

	for (auto element : result)
	{
		cout << "Name:\t" << element.name << "\tscore:\t" << element.score << endl;
	}
	*/


	/*
	*  STL find, find_if + sort
	*/
	/*auto result = find_if(people.begin(), people.end(), [](const Person &p)
		{
			return p.name == "name7";
		});

	if (result == people.end())
	{
		cout << "-";
	}
	else
	{
		cout << "+" << endl;
	}*/


	return 0;
}
