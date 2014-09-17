#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <utility>  // swap

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        ans.push_back("()");

        for (int i = 1; i < n; i++) {

            list<string> strList;
            for (string str : ans) {

                string tmpStr = "()" + str;
                strList.push_back(tmpStr);
                for (int j = 1; j < tmpStr.length() - 1; j++) {
                    swap(tmpStr[j], tmpStr[j + 1]);
                    strList.push_back(tmpStr);
                }

            }

            strList.sort();
            strList.unique();

            ans.clear();
            for (auto&& str : strList) {
                ans.push_back(str);
            }

        }

        return ans;
    }

    vector<string> generateParenthesis2(int n) {
        vector<string> ans;
        stack<string> candidateStack;
        stack<int> validationStack;

        candidateStack.push("(");
        validationStack.push(0);
        while (!candidateStack.empty()) {
            string s = candidateStack.top();
            int v = validationStack.top();
            candidateStack.pop();
            validationStack.pop();

            if (s.length() == n * 2) {
                ans.push_back(s);
                continue;
            }

            if (s.length() - v < n) {
                candidateStack.push(s + "(");
                validationStack.push(v);
            }

            if (v * 2 < s.length()) {
                candidateStack.push(s + ")");
                validationStack.push(v + 1);
            }
        }

        return ans;
    }
};


int main(int argc, char const* argv[])
{
    Solution solution;
    int val;
    while (1) {
        cin >> val;
        for (auto&& str : solution.generateParenthesis2(val)) {
            cout << str << endl;
        }
    }
    
    return 0;
}
