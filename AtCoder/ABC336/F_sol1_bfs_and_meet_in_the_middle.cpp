#include <bits/stdc++.h>
using namespace std;

using Grid = vector<vector<int>>;

void bfs(Grid srcGrid, map<Grid, int>& dist){
    const int ROWS = srcGrid.size();
    const int COLS = srcGrid[0].size();

    queue<Grid> q;
    dist.clear();

    q.push(srcGrid);
    dist[srcGrid] = 0;

    while(!q.empty()){
        Grid currentGrid = q.front();
        q.pop();

        if(dist[currentGrid] == 10){
            break;
        }

        for(int firstRow = 0; firstRow <= 1; ++firstRow){
            for(int firstCol = 0; firstCol <= 1; ++firstCol){
                int lastRow = firstRow + ROWS - 2;
                int lastCol = firstCol + COLS - 2;

                Grid nextGrid = currentGrid;
                for(int row1 = firstRow, row2 = lastRow; row1 < row2; ++row1, --row2){
                    for(int col = firstCol; col <= lastCol; ++col){
                        swap(nextGrid[row1][col], nextGrid[row2][col]);
                    }
                }

                for(int row = firstRow; row <= lastRow; ++row){
                    reverse(nextGrid[row].begin() + firstCol, nextGrid[row].begin() + lastCol + 1);
                }

                if(!dist.count(nextGrid)){
                    dist[nextGrid] = dist[currentGrid] + 1;
                    q.push(nextGrid);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ROWS, COLS;
    cin >> ROWS >> COLS;

    Grid grid(ROWS, vector<int>(COLS));
    for(int row = 0; row < ROWS; ++row){
        for(int col = 0; col < COLS; ++col){
            cin >> grid[row][col];
        }
    }

    Grid targetGrid(ROWS, vector<int>(COLS));
    for(int row = 0; row < ROWS; ++row){
        for(int col = 0; col < COLS; ++col){
            targetGrid[row][col] = row * COLS + col + 1;
        }
    }

    map<Grid, int> distFromSrc;
    bfs(grid, distFromSrc);

    map<Grid, int> distFromTarget;
    bfs(targetGrid, distFromTarget);

    const int INF = 1e9;
    int res = INF;
    for(pair<const Grid, int>& P: distFromSrc){
        const Grid& GRID = P.first;
        if(distFromTarget.count(GRID)){
            res = min(res, distFromSrc[GRID] + distFromTarget[GRID]);
        }
    }

    if(res == INF){
        res = -1;
    }

    cout << res;

    return 0;
}