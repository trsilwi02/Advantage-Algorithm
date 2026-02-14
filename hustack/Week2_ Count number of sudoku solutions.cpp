#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> emptyCell;
bool row[9][10], col[9][10], box[9][10];
long long solutions = 0;
int grid[9][9];

void GetSolution(int index) {
    if (index == emptyCell.size()) {
        solutions++;
        return;
    }

    int r = emptyCell[index].first;
    int c = emptyCell[index].second;
    int b = (r / 3) * 3 + (c / 3);

    for (int num = 1; num <= 9; num++) { 
        if (!row[r][num] && !col[c][num] && !box[b][num]) {
            row[r][num] = col[c][num] = box[b][num] = true;
            grid[r][c] = num;

            GetSolution(index + 1);

            row[r][num] = col[c][num] = box[b][num] = false;
            grid[r][c] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) {
                int val = grid[i][j];
                int b = (i / 3) * 3 + (j / 3);
                row[i][val] = col[j][val] = box[b][val] = true;
            } else {
                emptyCell.push_back({i, j});
            }
        }
    }

    GetSolution(0);

    cout << solutions << "\n";
    return 0;
}
