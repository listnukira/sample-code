#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        long long int up, down;
        up = rowIndex;
        down = 1;

        for (int i = 1; i <= (rowIndex + 1) / 2; i++) {
            row[i] = row[rowIndex - i] = (row[i - 1] * up) / down;

            up--;
            down++;
        }

        return row;
    }

    vector<int> getRow2(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);

        row[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for(int j = i; j > 0; j--) {
                row[j] += row[j - 1];
            }
        }

        return row;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    int rowIndex;

    while (true) {
        cin >> rowIndex;
        for (auto&& n : solution.getRow2(rowIndex)) {
            cout << n << " ";
        }
        cout << endl;
    }
    
    return 0;
}
