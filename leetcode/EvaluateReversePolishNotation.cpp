#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        string operators = "+-*/";
        int val1, val2;
        stack<int> operand;

        for (auto&& str : tokens) {
            if (operators.find(str) != string::npos) {
                val2 = operand.top();
                operand.pop();
                val1 = operand.top();
                operand.pop();

                operand.push(op(str, val1, val2));
            } else {
                operand.push(stoi(str));
            }
        }

        return operand.top();
    }

private:
    int op(string oper, int val1, int val2) {
        if (oper == "+")
            return val1 + val2;

        if (oper == "-")
            return val1 - val2;

        if (oper == "*")
            return val1 * val2;

        if (oper == "/")
            return val1 / val2;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");

    cout << solution.evalRPN(tokens) << endl;

    return 0;
}
