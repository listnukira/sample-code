#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        int maximum, prevMax, prevMin;
        maximum = prevMax = prevMin = A[0];

        for (int i = 1; i < n; i++) {
            int tmpMax = max(max(prevMax * A[i], prevMin * A[i]), A[i]);
            int tmpMin = min(min(prevMax * A[i], prevMin * A[i]), A[i]);
            if (tmpMax > maximum)
                maximum = tmpMax;

            prevMax = tmpMax;
            prevMin = tmpMin;
        }

        return maximum;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    int A[] = {-2, -3, -6};

    cout << solution.maxProduct(A, sizeof(A) / sizeof(int)) << endl;
    
    return 0;
}
