#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        istringstream istream(s);
        s = "";

        string word;
        while (istream >> word) {
            s = word + " " + s;
        }
        s = s.substr(0, s.length() - 1);
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    string line = "   the   sky is blue ";

    cout << line << endl;

    solution.reverseWords(line);

    cout << line << endl;
    
    return 0;
}
