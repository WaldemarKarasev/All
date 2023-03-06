#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

void PrintList(ListNode* node)
{
    int count = 0;
    
    while (node != NULL)
    {
        std::cout << "Node #" << count << ": value = "; 
        std::cout << node->val << std::endl;
            
        node = node->next;
        count++;
    }
}

ListNode* Solution(ListNode* list1, ListNode* list2)
{
    ListNode* temp;

    if(!list1)
    {
        return list2;
    }

    if (!list2)
    {
        return list1;
    }

    if (list1->val <= list2->val)
    {
        temp = Solution(list1->next, list2);
    }
    else
    {
        temp = Solution(list1, list2->next);
    }

    return temp;
    
}

int main()
{
    ListNode list1_0(0);
    ListNode list1_1(2);
    ListNode list1_2(4);

    list1_0.next = &list1_1;
    list1_1.next = &list1_2;


    ListNode list2_0(1);
    ListNode list2_1(3);
    ListNode list2_2(5);

    list2_0.next = &list1_1;
    list2_1.next = &list2_2;

    PrintList(&list1_0);
    PrintList(&list2_0);

    return 0;
}