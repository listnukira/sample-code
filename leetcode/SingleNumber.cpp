#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;

        for (int i = 0; i < n; i++) {
            result ^= A[i];
        }

        return result;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    int test1[] = {2};
    int test2[] = {2, 1, 4, 5, 2, 4, 1};
    int test3[] = {-1, 3, -1};

    cout << solution.singleNumber(test1, sizeof(test1) / sizeof(int)) << endl;
    cout << solution.singleNumber(test2, sizeof(test2) / sizeof(int)) << endl;
    cout << solution.singleNumber(test3, sizeof(test3) / sizeof(int)) << endl;
    
    return 0;
}
