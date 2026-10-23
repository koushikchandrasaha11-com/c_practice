#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<char> brackets;

    for (char ch : s)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            brackets.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (brackets.empty())
            {
                return false;
            }

            char top = brackets.top();
            brackets.pop();

            if (ch == ')' && top != '(')
                return false;
            if (ch == ']' && top != '[')
                return false;
            if (ch == '}' && top != '{')
                return false;
        }
    }
    return brackets.empty();
}
int main()
{
    string s;

    cout << "Enter a bracket string: ";
    cin >> s;

    if (isValid(s))
    {
        cout << "Valid brackets" << endl;
    }
    else
    {
        cout << "Invalid brackets" << endl;
    }

    return 0;
}