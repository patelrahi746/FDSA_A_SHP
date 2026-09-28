#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Check operator priority
int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

int main()
{
    string infix;
    string postfix = "";

    stack<char> s;

    cout << "Enter infix expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // If operand, add directly to postfix
        if (isalnum(ch))
        {
            postfix += ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            // Remove opening bracket
            if (!s.empty())
                s.pop();
        }

        // Operator
        else
        {
            while (!s.empty() &&
                   s.top() != '(' &&
                   priority(s.top()) >= priority(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}