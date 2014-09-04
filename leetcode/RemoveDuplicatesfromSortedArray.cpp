#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n)
{
    int val = 0, len = 0;
    for (int i = 0; i < n; i++) {

        if (len == 0 || (val ^ A[i]) != 0) {
            A[len++] = val = A[i];
        }
    }

    return len;
}

int main(int argc, char const* argv[])
{
    int array1[5] = {1, 1, 2, 3, 3};
    int zeroArray[5] = {0, 0, 0, 0, 0};

    int len1 = removeDuplicates(array1, 5);
    for (int i = 0; i < len1; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    int len2 = removeDuplicates(zeroArray, 5);
    for (int i = 0; i < len2; i++) {
        cout << zeroArray[i] << " ";
    }
    cout << endl;
    
    return 0;
}
