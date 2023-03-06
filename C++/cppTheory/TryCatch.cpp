#include <iostream>
#include <string>
#include<fstream>

using namespace std;

/*
* try catch
*/


int main()
{
	string path = "MyFile.txt";

	ifstream fin;
	
	fin.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
		cout << "Trying opening a file" << endl;
		fin.open(path);
		cout << "The file is open" << endl;
	}
	catch (const ifstream::failure& ex)
	{
		cout << ex.what() << endl;
		cout << ex.code() << endl;
		cout << endl;
		cout << "Error opening a file" << endl;
	}

	return 0;
}
