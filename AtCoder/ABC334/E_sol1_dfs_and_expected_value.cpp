#include <bits/stdc++.h>
using namespace std;

const long long MODULO = 998244353;

enum Color { GREEN = '#', RED = '.' };
vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int ROWS, COLS;

long long fastPow(long long a, long long n){
    a %= MODULO;
    long long res = 1;
    while(n > 0){
        if(n & 1){
            res = (res * a) % MODULO;
        }
        a = (a * a) % MODULO;
        n >>= 1;
    }
    return res;
}

long long modInverse(long long a){
    return fastPow(a, MODULO - 2);
}

bool isInside(int row, int col){
    return (0 <= row && row < ROWS && 0 <= col && col < COLS);
}

void dfs(int row, int col, vector<vector<int>>& cc, int ccCount, vector<string>& grid){
    if(!isInside(row, col)){
        return;
    }
    if(cc[row][col] != 0){
        return;
    }
    if(grid[row][col] != Color::GREEN){
        return;
    }
    cc[row][col] = ccCount;
    for(const pair<int, int>& DIRECTION: DIRECTIONS){
        int nextRow = row + DIRECTION.first;
        int nextCol = col + DIRECTION.second;
        dfs(nextRow, nextCol, cc, ccCount, grid);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> ROWS >> COLS;

    vector<string> grid(ROWS);
    for(int row = 0; row < ROWS; ++row){
        cin >> grid[row];
    }

    vector<vector<int>> cc(ROWS, vector<int>(COLS));
    int ccCount = 0;
    for(int row = 0; row < ROWS; ++row){
        for(int col = 0; col < COLS; ++col){
            if(grid[row][col] == Color::GREEN && cc[row][col] == 0){
                ccCount += 1;
                dfs(row, col, cc, ccCount, grid);
            }
        }
    }

    const long long TOTAL_CC = ccCount;
    long long resSum = 0;
    long long resCount = 0;

    for(int row = 0; row < ROWS; ++row){
        for(int col = 0; col < COLS; ++col){
            if(grid[row][col] == Color::RED){
                set<int> ccSet;
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    if(isInside(nextRow, nextCol) && grid[nextRow][nextCol] == Color::GREEN){
                        ccSet.insert(cc[nextRow][nextCol]);
                    }
                }
                
                resSum += TOTAL_CC - (int)ccSet.size() + 1;
                resSum %= MODULO;
                resCount += 1;
            }
        }
    }

    cout << resSum * modInverse(resCount) % MODULO;

    return 0;
}