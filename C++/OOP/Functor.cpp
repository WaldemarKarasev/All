#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


/*
* functor
*/
class MyFunctor
{
public:

	void operator ()()
	{
		cout << "I am Functor " << count << endl;
		count++;
	}

private:

	int count = 0;

};


/*
* predicate
*/
bool GraterThenZero(int a)
{
	return a > 0;
}

bool LessThenZero(int a)
{
	return a < 0;
}

/*
* binary predicate
*/

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

bool MyPred(int a, int b)
{
	return a < b;
}

int main()
{

	//vector<int> v = { 1,-3,2,-2,12,14,55,-3,-45,32, 100 };
	//
	////sort(v.begin(), v.end(), MyPred);
	//sort(v.begin(), v.end(), [](int a, int b) 
	//	{
	//		return a < b;
	//	});


	vector<Person> people
	{
		Person("name1", 100),
		Person("name2", 632),
		Person("name7", 200),
		Person("name8", 593),
		Person("name1", 293),
		Person("name6", 170),
		Person("name3", 195),
		Person("name4", 200),
		Person("name9", 300),

	};

	sort(people.begin(), people.end(), [](const Person &p1,const Person &p2) 
		{
			return p1.score < p2.score;
		});

	for (auto el : people)
	{
		cout << "Name  " << el.name << "\tScore  " << el.score << endl;
	}

	return 0;
}
