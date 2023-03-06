#include <iostream>
#include <string>

using namespace std;

class Image
{
public:
	
	void GetImageInfo()
	{
		for (int i = 0; i < LENGTH; i++)
		{
			cout << '#' << i << ' ' << pixels[i].GetInfo();
			cout << endl;
		}
	}

private:

	class Pixel
	{
	public:

		Pixel(int r, int g, int  b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}
		string GetInfo()
		{
			return "Pixel: r= " + to_string(r) + ", g= " + to_string(g) + ", b=" + to_string(b);
		}

	private:

		int r;
		int g;
		int b;

	};

	static const int LENGTH = 5;

	Pixel pixels[LENGTH]
	{
		Pixel (3,4,53),
		Pixel (117,3,72),
		Pixel (27,2,67),
		Pixel (87,1,174),
		Pixel (6,0,126),
	};

};

class Pixel
{
public:

	Pixel()
	{
		r = g = b = 0;
	}

	Pixel(int r, int g, int  b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
	string GetInfo()
	{
		return "Pixel: r= " + to_string(r) + ", g= " + to_string(g) + ", b=" + to_string(b);
	}

private:

	int r;
	int g;
	int b;

};


class Cap
{
public:
	string GetColor()
	{
		return color;
	}
private:
	string color = "red";
};

class Model
{
public:
	void InspectModel()
	{
		cout << "Model's cap is " << cap.GetColor() << endl;
	}
private:
	Cap cap;
};


class Human
{
public:
	
	void Think()
	{
		brain.Think();
	}

	void InspectTheCap()
	{
		cout << "Cap is " << cap.GetColor() << endl;
	}

private:

	class Brain
	{
	public:
		
		void Think()
		{
			cout << "Think" << endl;
		}
	};
	Brain brain;
	Cap cap;

};


int main()
{
	Human man;
	man.Think();
	man.InspectTheCap();

	Model model;
	model.InspectModel();

}