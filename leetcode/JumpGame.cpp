#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 1)
            return true;

        int step = A[0];
        for (int i = 1; i < n - 1 && step > 0; i++)
            step = max(step - 1, A[i]);

        return (step > 0) ? true : false;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;

    int A1[] = {1, 1, 0, 1};
    int A2[] = {0};
    int A3[] = {1, 2};
    int A4[] = {2, 0, 0};

    cout << solution.canJump(A1, sizeof(A1) / sizeof(int)) << endl;
    cout << solution.canJump(A2, sizeof(A2) / sizeof(int)) << endl;
    cout << solution.canJump(A3, sizeof(A3) / sizeof(int)) << endl;
    cout << solution.canJump(A4, sizeof(A4) / sizeof(int)) << endl;
    
    return 0;
}
