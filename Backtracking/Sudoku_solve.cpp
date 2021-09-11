// learned from geeksforgeeks
#include <bits/stdc++.h>
using namespace std;
//
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mx 100010
#define mod 1000000007
#define inf INT_MAX
#define pi acos(-1)
#define endl '\n'
#define fin freopen("input", "r", stdin)
#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//

const int n = 9;

bool isSafe(int grid[n][n], int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == val) return false;
    }

    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == val) return false;
    }

    int sR = (row / 3) * 3;
    int sC = (col / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + sR][j + sC] == val) return false;
        }
    }

    return true;
}

bool solveSudoku(int grid[n][n], int row, int col) {
    if (row == n - 1 && col == n) return true;

    if (col == n) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col + 1);
    }

    for (int i = 1; i <= n; i++) {
        if (isSafe(grid, row, col, i)) {
            grid[row][col] = i;

            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }
        }

        grid[row][col] = 0;
    }

    return false;
}

void printSudoku(int grid[n][n]) {
    cout << endl << endl << "The Sudoku is: " << endl << endl;
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {
            cout << "\t ";
            for (int j = 0; j <= 27; j++) cout << "_";
            cout << endl << endl;
        }
        cout << "\t";
        for (int j = 0; j < n; j++) {
            if (j % 3 == 0) cout << " | ";
            cout << grid[i][j] << " ";
            if (j == 8) cout << " | ";
        }

        cout << endl;
        if (i == 8) {
            cout << "\t ";
            for (int j = 0; j <= 27; j++) cout << "_";
        }
    }
    cout << endl << endl << endl;
}

int main() {
    int grid[n][n];
    cout << endl << "Enter the sudoku:" << endl << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
        }
    }

    if (solveSudoku(grid, 0, 0)) {
        printSudoku(grid);
    }
    else {
        cout << "NOT POSSIBLE" << endl;
    }

    getchar();
}
/*
Sample input:
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/