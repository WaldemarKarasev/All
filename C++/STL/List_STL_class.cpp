#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename T>
void PrintList(const list<T> & list)
{
    for (auto i = list.cbegin(); i != list.cend(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    list<int> myList = { 1000, 10,11,12, 99,88, 88, 99,99 };
    myList.push_back(100);
    myList.push_front(1);
    list<int>::iterator it = myList.begin();

    myList.unique();
    PrintList(myList);
    cout << myList.size() << endl;
    PrintList(myList);


    myList.pop_back();
    myList.pop_front();
    PrintList(myList);
    

    myList.reverse();
    PrintList(myList);

   auto in = myList.begin();
   advance(in, 4);
   myList.insert(in, 111);
   PrintList(myList);

   advance(in, -2);
   myList.insert(in, 111);
   PrintList(myList);

    myList.clear();
    PrintList(myList);
    
    myList.assign(5,101);
    PrintList(myList);

    list<int> myList2;
    myList2.assign(myList.begin(), myList.end());
    PrintList(myList2);


    return 0;
}
