

class List
{
private:
    
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

