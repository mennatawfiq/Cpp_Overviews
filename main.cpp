#include <iostream>
#include <string>
using namespace std;

template <typename t>
class myStack
{ // don't forget to check for the access modifiers
public:
    t *_top;
    myStack()
    {
        _top = NULL;
    }
    bool isEmpty() const
    {
        return _top == NULL;
    }
    t *top() const
    {
        return _top;
    }
    void push(char data)
    {
        t *node = new t(data);
        if (!isEmpty())
        {
            node->next = _top;
        }
        _top = node;
    }
    void pop()
    {
        t *del = _top;
        _top = _top->next;
        delete del;
    }
};

class stackNode
{
private:
    char data;
    stackNode *next;
    stackNode(char data = '0')
    {
        this->data = data;
        next = NULL;
    }
    template <typename t>
    friend class myStack;
};

bool isBalanced(const string &s)
{
    myStack<stackNode> st;
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

void init();

int main()
{
    init();
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
    catch (const char *ex)
    {
        cout << ex << endl;
    }
}