#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    map<char, char> parentthesesMap;

    Solution() {
        parentthesesMap[')'] = '(';
        parentthesesMap[']'] = '[';
        parentthesesMap['}'] = '{';
    }

    bool isValid(string s) {
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
};


int main(int argc, char const* argv[])
{
    Solution solution;
    string str;

    while (1) {
        cin >> str;
        cout << solution.isValid(str) << endl;
    }
    
    return 0;
}
