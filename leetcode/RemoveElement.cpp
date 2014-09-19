#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != elem)
                A[len++] = A[i];
        }

        return len;
    }
};


int main(int argc, char const* argv[])
{
    Solution solution;
    int array[] = {1, 3, 4, 3, 3};

    int len1 = solution.removeElement(array, sizeof(array) / sizeof(int), 3);
    for (int i = 0; i < len1; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
