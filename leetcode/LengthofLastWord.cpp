#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0;

        while (*s != '\0') {
            if (*s++ != ' ') {
                length++;
            } else if (*s && *s != ' ') {
                length = 0;
            }
        }

        return length;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;

    cout << solution.lengthOfLastWord("a  ") << endl;
    
    cout << solution.lengthOfLastWord("Today is a nice day") << endl;

    return 0;
}
