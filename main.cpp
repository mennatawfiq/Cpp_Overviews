#include <iostream>
#include <string>
using namespace std;

class myStack;

class stackNode
{
    char data;
    stackNode *next;
    stackNode(char data = '0')
    {
        this->data = data;
        next = NULL;
    }
    friend class myStack;
};

class myStack
{ // don't forget to check for the access modifiers
public:
    stackNode *_top;
    myStack()
    {
        _top = NULL;
    }
    bool isEmpty() const
    {
        return _top == NULL;
    }
    stackNode *top() const
    {
        return _top;
    }
    void push(char data)
    {
        stackNode *node = new stackNode(data);
        if (!isEmpty())
        {
            node->next = _top;
        }
        _top = node;
    }
    void pop()
    {
        stackNode *del = _top;
        _top = _top->next;
        delete del;
    }
};

bool isBalanced(const string &s)
{
    myStack st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.isEmpty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.isEmpty();
}

int main()
{
    return 0;
}

void init()
{
    cout << "Welcome to our program -Arithmatic exeprission evaluation." << endl;
    cout << "Currently, our program works on numbers from 0 to 9 only." << endl;
    cout << "Enter your exeprission to evaluate : ";
    string s;
    getline(cin, s);
    try
    {
        if (!isBalanced(s))
        {
            throw "The exepression is not valid to evaluate!";
        }
    }
    catch (const char &ex)
    {
        cout << ex << endl;
    }
}