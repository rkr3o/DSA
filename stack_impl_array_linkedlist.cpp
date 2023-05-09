// stack using linkedlist
// instead of linkedlist vector can be veey useful
struct Node
{
    int val;
    Node* next ;
    Node(int x )
    {
        val = x ;
        next = NULL;
    }
};
class StackLL
{
    Node* top ;
public:
    StackLL()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node* n = new Node(data);
        n->next = top;
        top = n;
    }
    void pop()
    {
        if (top != NULL)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    int getTop()
    {
        if (top != NULL)
        {
            return top->val;
        }
        return -1;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
};

// stack using array
int arr[N];

class Stack
{
public:
    int top = -1;
    void push(int t)
    {
        if (top == N - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = t;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            --top;
        }
    }
    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    int size()
    {
        return top + 1;
    }
    void print()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; --i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
