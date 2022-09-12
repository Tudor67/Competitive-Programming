class DSU{
private:
    vector<int> rank;
    vector<int> parent;
    
public:
    DSU(const int& N){
        rank.resize(N);
        parent.resize(N);
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
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
private:
    int getIdx(int row, int col, const int& COLS){
        return (row * COLS + col);
    }
    
    void addArcs(vector<tuple<int, int, int>>& v, DSU& dsu, vector<vector<int>>& G, const int& COLS){
        for(int i = 1; i < (int)v.size(); ++i){
            int prevVal, prevRow, prevCol;
            tie(prevVal, prevRow, prevCol) = v[i - 1];
            int val, row, col;
            tie(val, row, col) = v[i];
            if(prevVal != val){
                int node = dsu.find(getIdx(prevRow, prevCol, COLS));
                int nextNode = dsu.find(getIdx(row, col, COLS));
                G[node].push_back(nextNode);
            }
        }
    }
    
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        // DSU to create connected components for equal elements which share a common row or column
        DSU dsu(getIdx(ROWS - 1, COLS - 1, COLS) + 1);
        
        unordered_map<int, int> prevColOf;
        for(int row = 0; row < ROWS; ++row){
            prevColOf.clear();
            for(int col = 0; col < COLS; ++col){
                int val = matrix[row][col];
                if(prevColOf.count(val)){
                    dsu.join(getIdx(row, prevColOf[val], COLS), getIdx(row, col, COLS));
                }
                prevColOf[val] = col;
            }
        }
        
        unordered_map<int, int> prevRowOf;
        for(int col = 0; col < COLS; ++col){
            prevRowOf.clear();
            for(int row = 0; row < ROWS; ++row){
                int val = matrix[row][col];
                if(prevRowOf.count(val)){
                    dsu.join(getIdx(prevRowOf[val], col, COLS), getIdx(row, col, COLS));
                }
                prevRowOf[val] = row;
            }
        }
        
        // Graph G on connected components
        vector<vector<int>> G(ROWS * COLS);
        vector<tuple<int, int, int>> v;
        for(int row = 0; row < ROWS; ++row){
            v.clear();
            for(int col = 0; col < COLS; ++col){
                v.emplace_back(matrix[row][col], row, col);
            }
            sort(v.begin(), v.end());
            addArcs(v, dsu, G, COLS);
        }
        
        for(int col = 0; col < COLS; ++col){
            v.clear();
            for(int row = 0; row < ROWS; ++row){
                v.emplace_back(matrix[row][col], row, col);
            }
            sort(v.begin(), v.end());
            addArcs(v, dsu, G, COLS);
        }
        
        // Topological sort on graph G
        vector<int> inDegree(ROWS * COLS);
        for(int node = 0; node < (int)G.size(); ++node){
            for(int nextNode: G[node]){
                inDegree[nextNode] += 1;
            }
        }
        
        vector<int> rankVector(ROWS * COLS);
        queue<int> q;
        for(int node = 0; node < (int)G.size(); ++node){
            if(inDegree[node] == 0){
                q.push(node);
                rankVector[node] = 1;
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: G[node]){
                inDegree[nextNode] -= 1;
                rankVector[nextNode] = rankVector[node] + 1;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }
        
        // Create res from rankVector
        vector<vector<int>> res(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int node = dsu.find(getIdx(row, col, COLS));
                res[row][col] = rankVector[node];
            }
        }
        
        return res;
    }
};