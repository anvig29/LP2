#include <iostream>
#include <string>
using namespace std;

class Solution {
public: 
    string result[100][100]; // Assuming a maximum size for the result array
    int solutionCount;

    bool isValid(string board[100][100], int row, int col, int n) {
        // Look for up
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == "Q")
                return false;
        }

        // Check left diagonal upwards
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == "Q")
                return false;
        }

        // Check right diagonal upwards
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == "Q")
                return false;
        }
        return true;
    }

    void solve(string board[100][100], int row, int n) {
        if (row == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    result[solutionCount][i] += board[i][j]; // Copy board to result
                }
            }
            solutionCount++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(board, row, i, n)) {
                board[row][i] = "Q";
                solve(board, row + 1, n);
                board[row][i] = ".";
            }
        }
    }

    void solveNQueens(int n) {
        solutionCount = 0;
        string board[100][100]; // Assuming a maximum size for the board array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = ".";
            }
        }
        solve(board, 0, n);
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution sol;
    sol.solveNQueens(n);

    for (int b = 0; b < sol.solutionCount; b++) {
        cout << "Solution " << b + 1 << ":" << endl;
        for (int i = 0; i < n; i++) {
            cout << sol.result[b][i] << endl;
        }
        cout << endl;
    }
    return 0;
}
