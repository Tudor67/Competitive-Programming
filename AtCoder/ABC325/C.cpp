#include <bits/stdc++.h>
using namespace std;

const char SENSOR = '#';

void dfs(int row, int col, vector<string>& grid, vector<vector<bool>>& vis){
    const int ROWS = grid.size();
    const int COLS = grid[0].length();
    if(row < 0 || ROWS <= row || col < 0 || COLS <= col){
        return;
    }
    if(vis[row][col] || grid[row][col] != SENSOR){
        return;
    }
    vis[row][col] = true;
    for(int rowDir = -1; rowDir <= 1; ++rowDir){
        for(int colDir = -1; colDir <= 1; ++colDir){
            dfs(row + rowDir, col + colDir, grid, vis);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ROWS, COLS;
    cin >> ROWS >> COLS;

    vector<string> grid(ROWS);
    for(int row = 0; row < ROWS; ++row){
        cin >> grid[row];
    }

    int res = 0;
    vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
    for(int row = 0; row < ROWS; ++row){
        for(int col = 0; col < COLS; ++col){
            if(grid[row][col] == SENSOR){
                if(!vis[row][col]){
                    res += 1;
                    dfs(row, col, grid, vis);
                }
            }
        }
    }

    cout << res;

    return 0;
}