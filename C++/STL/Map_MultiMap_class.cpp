#include <iostream>
#include <map>
#include <string>

using namespace std;





int main()
{
	map<int, string> myMap;

	pair<int, string> p(1, "id");

	myMap.emplace(1, "aaaaa");
	myMap.emplace(2, "bbbbb");
	myMap.emplace(3, "ccccc");
	myMap.emplace(4, "ddddd");

	auto it = myMap.find(2);

	cout << it->second << endl;

	cout << endl;

	cout << myMap[2];
	return 0;
}