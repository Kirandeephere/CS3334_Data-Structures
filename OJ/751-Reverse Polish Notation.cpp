/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 237101
 * Submitted at:  2022-12-03 15:29:31
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    751
 * Problem Name:  Reverse Polish Notation
 */

#include<iostream>
#include<stack>
#include <string>
#include<vector>


using namespace std;
int x = 0;
int Cal(string  Str)
{
    x++;
    stack<int> stack;
    int len = Str.length();
    x--;
    for (int i = 0; i < len; i++)
    {
        if (Str.at(i) >= '0' && Str.at(i) <= '9')
        {
            x++;
            stack.push(Str.at(i) - '0');
        }
        else if (Str.at(i) == 32)
        {
            x--;
            continue;
        }
        else
        {
            int a = stack.top();
            stack.pop();
            x++;
            int b = stack.top();
            stack.pop();
            x--;
            switch (Str.at(i))
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
    x++;
    return stack.top();
}

int main(){

    string Str = " ";
    int y = 0;
    vector<int> result;
    while (getline(cin, Str))
    {
        y++;
        if (Str.empty()) {
            break;
            y--;
        }
        result.push_back(Cal(Str));
        y++;
    }

    for (int j = 0; j < result.size(); j++)
    {
        y++;
        cout << result.at(j);
        if (j < result.size() - 1)
        {
            y--;
            cout << endl;
        }
    }
    y++;
    cout << endl;
}