#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

static map<char, char> parentthesesMap;

bool isValid(string s)
{
    stack<char> stk;

    for (auto&& ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stk.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (!stk.empty() && stk.top() == parentthesesMap[ch])
                stk.pop();
            else
                return false;
        } else {}
    }

    return stk.empty() ? true : false;
}

int main(int argc, char const* argv[])
{
    parentthesesMap[')'] = '(';
    parentthesesMap[']'] = '[';
    parentthesesMap['}'] = '{';

    string str;
    while (1) {
        cin >> str;
        cout << isValid(str) << endl;
    }
    
    return 0;
}
