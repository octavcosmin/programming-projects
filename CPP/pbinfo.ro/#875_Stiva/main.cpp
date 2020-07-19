#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack <int> myStack;
    string opperation;
    int n, temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> opperation;
        if (opperation == "push")
        {
            cin >> temp;
            myStack.push(temp);
        }
        else
            if (opperation == "top" && !myStack.empty())
                cout << myStack.top() << '\n';
            else
                if (opperation == "pop" && !myStack.empty())
                    myStack.pop();
    }
    return 0;
}
