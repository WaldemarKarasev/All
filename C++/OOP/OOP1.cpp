#include <iostream>
#include <string>

using namespace std;

class Apple;

class Human
{
public:

	void takeApple(Apple& apple);
	
	void EatAppel(Apple& apple)
	{
		
	}

	friend void Print(Human& man);
	

private:
	int age;

};


class Apple
{
	friend Human;

public:
	

	Apple(int weight, string color)
	{
		this->color = color;
		this->weight = weight;
		Count++;
		id = Count;
	}

	int GetId()
	{
		return id;	
	}

	string GetColor()
	{
		return color;
	}

	static int GetCount()
	{
		return Count;
	}

	static void ChangeColor(Apple& apple, string color)
	{
		apple.color = color;
	}

	void ChangeColorNonStatic(string color)
	{
		this->color = color;
	}

private:
	static int Count;
	int id;
	int weight;
	string color;
	
};

int Apple::Count = 0;

void Print(Human& man)
{
	cout << "Hello" << endl;
}

int main()
{
		
	return 0;
}

void Human::takeApple(Apple& apple)
{
	cout << "TakeApple " << "weight =  " << apple.weight << ", color = " << apple.color << endl;
	
}
