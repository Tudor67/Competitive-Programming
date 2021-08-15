class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N){
        rank.resize(N + 1);
        parent.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                rank[yRoot] += (rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
private:    
    int getNodeIdx(int row, int col, const int& COLS){
        return (row * COLS + col);
    }
    
    void dfs(int node, vector<vector<int>>& g, vector<int>& h){
        if(g[node].empty()){
            h[node] = 1;
        }else if(h[node] == -1){
            for(int nextNode: g[node]){
                dfs(nextNode, g, h);
                h[node] = max(h[node], 1 + h[nextNode]);
            }
        }
    }
    
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        const int N = ROWS * COLS;
        
        // Connected components
        DSU dsu(N);
        unordered_map<int, int> prevColOf;
        for(int row = 0; row < ROWS; ++row){
            prevColOf.clear();
            for(int col = 0; col < COLS; ++col){
                if(prevColOf.count(matrix[row][col])){
                    dsu.join(getNodeIdx(row, prevColOf[matrix[row][col]], COLS), getNodeIdx(row, col, COLS));
                }
                prevColOf[matrix[row][col]] = col;
            }
        }
        
        unordered_map<int, int> prevRowOf;
        for(int col = 0; col < COLS; ++col){
            prevRowOf.clear();
            for(int row = 0; row < ROWS; ++row){
                if(prevRowOf.count(matrix[row][col])){
                    dsu.join(getNodeIdx(prevRowOf[matrix[row][col]], col, COLS), getNodeIdx(row, col, COLS));
                }
                prevRowOf[matrix[row][col]] = row;
            }
        }
        
        // Graph on connected components
        vector<vector<int>> g(N);
        vector<pair<int, int>> v;
        v.resize(COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                v[col] = {matrix[row][col], col};
            }
            sort(v.begin(), v.end());
            for(int i = 1; i < COLS; ++i){
                if(v[i - 1].first < v[i].first){
                    int col = v[i].second;
                    int nextCol = v[i - 1].second;
                    int node = dsu.find(getNodeIdx(row, col, COLS));
                    int nextNode = dsu.find(getNodeIdx(row, nextCol, COLS));
                    g[node].push_back(nextNode);
                }
            }
        }
        
        v.resize(ROWS);
        for(int col = 0; col < COLS; ++col){
            for(int row = 0; row < ROWS; ++row){
                v[row] = {matrix[row][col], row};
            }
            sort(v.begin(), v.end());
            for(int i = 1; i < ROWS; ++i){
                if(v[i - 1].first < v[i].first){
                    int row = v[i].second;
                    int nextRow = v[i - 1].second;
                    int node = dsu.find(getNodeIdx(row, col, COLS));
                    int nextNode = dsu.find(getNodeIdx(nextRow, col, COLS));
                    g[node].push_back(nextNode);
                }
            }
        }
        
        // DFS
        vector<vector<int>> answer(ROWS, vector<int>(COLS));
        vector<int> h(N, -1);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int node = dsu.find(getNodeIdx(row, col, COLS));
                dfs(node, g, h);
                answer[row][col] = h[node];
            }
        }
        
        return answer;
    }
};