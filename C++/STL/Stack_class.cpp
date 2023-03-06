#include <iostream>



#include<list>
#include<deque>
#include <queue>

//+all for queue
#include<vector>
#include <stack>

using namespace std;


int main()
{
    //stack
    /*
    stack<int> st;

    st.push(1);
    st.push(2);
    st.emplace(3);
    st.emplace(4);


    //while (!st.empty())
    //{
    //    cout << st.top() << endl;
    //    st.pop();
    //}

    auto a = st._Get_container();
    */


    //queue, priority_queue
    priority_queue<int> q;

    q.push(100);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    

    while (!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
        cout << "Elemenst count " << q.size() << endl;
    }


    /*
    queue<int, list<int>> q;
    
    

    cout << "Elemenst count " << q.size() << endl;
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
        cout << "Elemenst count " << q.size() << endl;
    }


    auto a = q._Get_container();*/


    return 0;
}