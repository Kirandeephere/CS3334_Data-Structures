#include<iostream>
#include<stack>
#include<string>
using namespace std;

int RPN(string S)
{
    stack<int> stack;
    int length = S.length();

    for (int i = 0; i < length; i++)
    {
        if (S[i] >= '0' && S[i] <= '9')
        {
            stack.push(S[i] - '0');
        }
        else if (S[i] == ' ')
        {
            continue;
        }
        else
        {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();

            switch (S[i])
            {
            case '+':
                stack.push(b + a);
                break;
            case '-':
                stack.push(b - a);
                break;
            case '*':
                stack.push(b * a);
                break;
            }
        }
    }
}