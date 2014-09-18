#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    void solve(vector< vector<char> > &board) {
        if (board.size() == 0)
            return;

        int rowLen = board.size();
        int colLen = board[0].size();

        vector< vector<bool> > needFlip(rowLen, vector<bool>(colLen, true));

        for (int i = 0; i < rowLen; i++) {
            for (int j = 0; j < colLen; j++) {
                if (board[i][j] == 'X')
                    continue;

                if (i == 0 || i == rowLen - 1 || j == 0 || j == colLen - 1)
                    coordinate.push(make_pair(i, j));
            }
        }

        while (!coordinate.empty()) {
            int i = coordinate.top().first;
            int j = coordinate.top().second;
            coordinate.pop();

            needFlip[i][j] = false;
            if (i - 1 >= 0 && board[i - 1][j] == 'O' && needFlip[i - 1][j] == true)
                coordinate.push(make_pair(i - 1, j));

            if (i + 1 < rowLen && board[i + 1][j] == 'O' && needFlip[i + 1][j] == true)
                coordinate.push(make_pair(i + 1, j));

            if (j - 1 >= 0 && board[i][j - 1] == 'O' && needFlip[i][j - 1] == true)
                coordinate.push(make_pair(i, j - 1));

            if (j + 1 < colLen && board[i][j + 1] == 'O' && needFlip[i][j + 1] == true)
                coordinate.push(make_pair(i, j + 1));
        }

        for (int i = 1; i < rowLen - 1; i++)
            for (int j = 1; j < colLen - 1; j++)
                if (needFlip[i][j] == true)
                    board[i][j] = 'X';

    }

private:
    stack< pair<int, int> > coordinate;
};

int main(int argc, char const* argv[])
{
    Solution solution;
    vector< vector<char> > board(4, vector<char>(4, 'X'));

    board[1][1] = board[1][2] = board[2][2] = board[3][1] = 'O';

    /* before */
    for (auto&& rows : board) {
        for (auto&& ch : rows) {
            cout << ch << " ";
        }
        cout << endl;
    }

    cout << endl;
    solution.solve(board);
    cout << endl;

    /* after */
    for (auto&& rows : board) {
        for (auto&& ch : rows) {
            cout << ch << " ";
        }
        cout << endl;
    }
    
    return 0;
}
