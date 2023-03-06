#include <iostream>

struct Node
{
    int data;
    Node *next;
};


class LinkedList
{
private:
    Node* head;
    Node* tail;

public:

    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }    

    void Add_Node(int data)
    {
        Node *tmp = new Node;
        tmp->data = data;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }
   
    Node* GetHead()
    {
        return head;
    }
};


class Solution
{
public:

    bool isPalindrome(Node* head)
    {
        Node* slow = head;
        Node* fast = head;
        Node* prev;
        Node* tmp;

        while(fast && fast->next == NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        prev = slow;
        slow = slow->next;
        prev->next =  NULL;

        while (slow)
        {
            tmp = slow->next;
            slow->next = prev;
            prev= slow;
            slow = tmp;
        }

        fast = head;
        slow = prev;

        while (slow)
        {
            if (fast->data != slow->data)
            {
                return false;
            }
            else
            {
                fast = fast->next;
                slow = slow->next;
            }
            return true;//removing this => and program does not work
        }
        return true;
        
        
    }

};

int main()
{
    LinkedList list;
    list.Add_Node(1);
    list.Add_Node(2);
    list.Add_Node(2);
    list.Add_Node(1);

    Node* nd = list.GetHead();

    Solution sln;
    std::cout << sln.isPalindrome(nd) << '\n';

    return 0;
}