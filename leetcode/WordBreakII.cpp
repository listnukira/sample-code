#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> recursive(string s, unordered_set<string> &dict) {
        string rightStr, leftStr;
        vector<string> ret;

        if (dict.find(s) != dict.end())
            ret.push_back(s);

        int len = s.length();
        for(int i = 1; i < len; i++) {
            leftStr = s.substr(0, i);
            rightStr = s.substr(i, len - i);

            if (dict.find(leftStr) != dict.end()) {
                vector<string> recRet = recursive(rightStr, dict);
                for (int j = 0; j < recRet.size(); j++) {
                    ret.push_back(leftStr + " " + recRet[j]);
                }
            }
        }

        return ret;
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        vector<bool> canSegment(len + 1, false);
        vector<string> ans;

        canSegment[0] = true;
        for (int i = 1; i < len + 1; i++) {
            for (int j = 0; j < i; j++) {
                unordered_set<string>::const_iterator it = dict.find(s.substr(j, i - j));
                if (canSegment[j] && it != dict.end()) {
                    canSegment[i] = true;
                    break;
                }
            }
        }

        if (canSegment[len] == true)
            ans = recursive(s, dict);

        return ans;
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

    for (auto&& str : solution.wordBreak(s1, dict1)) {
        cout << str << endl;
    }

    return 0;
}
