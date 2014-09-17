#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        vector<bool> canSegment(len + 1, false);

        canSegment[0] = true;
        for (int i = 1; i < len + 1; i++) {
            for (int j = 0; j < i; j++) {
                if (canSegment[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    canSegment[i] = true;
                    break;
                }
            }
        }

        return canSegment[len];
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    string s1 = "regulartest";
    string s2 = "aaaaaaa";
    string s3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";

    unordered_set<string> dict1, dict2, dict3;

    dict1.insert("re");
    dict1.insert("gu");
    dict1.insert("lar");
    dict1.insert("test");
    dict1.insert("regu");
    dict1.insert("lartest");

    dict2.insert("aaaa");
    dict2.insert("aa");
    dict2.insert("a");

    dict3.insert("a");
    dict3.insert("aa");
    dict3.insert("aaa");
    dict3.insert("aaaa");
    dict3.insert("aaaaa");
    dict3.insert("aaaaaa");
    dict3.insert("aaaaaaa");
    dict3.insert("aaaaaaaa");
    dict3.insert("aaaaaaaaa");
    dict3.insert("aaaaaaaaaa");

    cout << solution.wordBreak(s1, dict1) << endl;
    cout << solution.wordBreak(s2, dict2) << endl;
    cout << solution.wordBreak(s3, dict3) << endl;

    return 0;
}
