#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        if (n == 0)
            return "";

        for (int i = 1; i < n; i++) {
            string tmp = "";
            char val = s[0];
            int cnt = 1;

            for (int j = 1; j < s.length(); j++) {
                if (s[j] == val) {
                    cnt++;
                    continue;
                }

                tmp += to_string(cnt) + val;
                val = s[j];
                cnt = 1;
            }

            tmp += to_string(cnt) + val;
            s = tmp;
        }

        return s;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;

    cout << solution.countAndSay(2) << endl; // 11
    cout << solution.countAndSay(5) << endl; // 111221
    
    return 0;
}
