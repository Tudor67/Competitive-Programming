#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
enum CellColor { RED = '.', GREEN = '#'};

const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
const long long MODULO = 998244353;

int cellToNode(int row, int col, const int COLS){
    return row * COLS + col;
}

bool isInside(int row, int col, const int ROWS, const int COLS){
    return (0 <= row && row < ROWS && 0 <= col && col < COLS);
}

void dfs(int parent, int node, int& currentTime, vector<bool>& vis,
         vector<int>& tin, vector<int>& low, long long& extraCC, const Graph& G){
    vis[node] = true;

    currentTime += 1;
    tin[node] = currentTime;
    low[node] = currentTime;

    int children = 0;
    for(int nextNode: G[node]){
        if(nextNode == parent){
            
        }else if(vis[nextNode]){
            low[node] = min(low[node], tin[nextNode]);
        }else{
            dfs(node, nextNode, currentTime, vis, tin, low, extraCC, G);
            low[node] = min(low[node], low[nextNode]);
            if(tin[node] <= low[nextNode] && parent != -1){
                extraCC += 1;
            }
            children += 1;
        }
    }

    if(parent == -1 && children >= 2){
        extraCC += children - 1;
    }
}

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ROWS, COLS;
    cin >> ROWS >> COLS;

    vector<string> grid(ROWS);
    for(int row = 0; row < ROWS; ++row){
        cin >> grid[row];
    }

    const int N = ROWS * COLS;
    Graph G(N);
    for(int row = 0; row < ROWS; ++row){
        for(int col = 0; col < COLS; ++col){
            if(grid[row][col] == CellColor::GREEN){
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    if(isInside(nextRow, nextCol, ROWS, COLS) &&
                       grid[nextRow][nextCol] == CellColor::GREEN){
                        int node = cellToNode(row, col, COLS);
                        int nextNode = cellToNode(nextRow, nextCol, COLS);
                        G[node].push_back(nextNode);
                    }
                }
            }
        }
    }

    vector<bool> vis(N);
    vector<int> tin(N);
    vector<int> low(N);
    long long extraCC = 0;
    long long totalCC = 0;

    for(int row = 0; row < ROWS; ++row){
        for(int col = 0; col < COLS; ++col){
            int node = cellToNode(row, col, COLS);
            if(grid[row][col] == CellColor::GREEN && !vis[node]){
                totalCC += 1;
                
                if(G[node].empty()){
                    extraCC -= 1;
                }else{
                    int currentTime = 0;
                    dfs(-1, node, currentTime, vis, tin, low, extraCC, G);
                }
            }
        }
    }

    long long greenCellsCount = 0;
    for(int row = 0; row < ROWS; ++row){
        greenCellsCount += count(grid[row].begin(), grid[row].end(), CellColor::GREEN);
    }

    cout << (totalCC * greenCellsCount + extraCC) % MODULO *
            modInverse(greenCellsCount) % MODULO;

    return 0;
}