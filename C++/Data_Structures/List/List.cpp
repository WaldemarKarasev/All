#include <iostream>

class List
{
private:
public:
    struct Node
    {
        int data = 0;
        Node* next;

        Node()
        {
            data = 0;
            next = nullptr;
        }
        Node(int data)
            : data(data)
            , next(nullptr)
        {}

    };

    Node* head = nullptr;

public:
    List() { head = nullptr; }
    List(int data);
    ~List();

    void pushBack(int data);
    void printList();
    void deleteNode(int NodeNumber);
};

List::List(int data)
{
    head = new Node(0);
    Node* node = new Node(data);
    this->head->next = node;
}

List::~List()
{

}

void List::pushBack(int data)
{
    Node* tmp = head;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }

    Node* newNode = new Node(data);
    tmp->next = newNode;

}

void List::printList()
{
    Node* current = this->head;
    std::cout << "head->";
    while (current != nullptr)
    {
        if (current->next == nullptr)
        {
            std::cout << current->data << " ";
        }
        else
        {
            std::cout << current->data << "->";
        }

        current = current->next;
    }

    std::cout << "\n";
}

void List::deleteNode(int NodeNumber)
{
    //NodeNumber;
   
    Node* curr = nullptr;
    Node* prev = nullptr;

    curr = head;

    while (NodeNumber != 0)
    {
        prev = curr;
        curr = curr->next;

        NodeNumber--;
    }
    prev->next = curr->next;
    delete curr;

    //curr->next = nullptr;
}

int main()
{
    std::cout << "Hello World!\n";

    List list(1);
    list.pushBack(2);
    list.pushBack(3);

    list.printList();

    list.deleteNode(2);

    list.printList();
    std::cout << sizeof(List::Node*);
}
