class DSU{
private:
    const int N;
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N): N(N){
        reset();
    }
    
    void reset(){
        rank.resize(N + 1);
        parent.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);
        fill(rank.begin(), rank.end(), 0);
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
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        const int SHIFT = ROWS;
        
        map<int, vector<pair<int, int>>> coordinatesOf;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                coordinatesOf[matrix[row][col]].emplace_back(row, col);
            }
        }
        
        vector<vector<int>> answer(ROWS, vector<int>(COLS));
        vector<int> rowRank(ROWS, 0);
        vector<int> colRank(COLS, 0);
        DSU dsu(COLS + SHIFT);
        vector<int> groupRank(COLS + SHIFT + 1);
        for(const pair<int, vector<pair<int, int>>>& P: coordinatesOf){
            const int& VAL = P.first;
            const vector<pair<int, int>>& COORDINATES = P.second;
            
            dsu.reset();
            for(const pair<int, int>& COORDINATE: COORDINATES){
                int row = COORDINATE.first;
                int col = COORDINATE.second;
                dsu.join(row, col + SHIFT);
            }
            
            fill(groupRank.begin(), groupRank.end(), 0);
            for(const pair<int, int>& COORDINATE: COORDINATES){
                int row = COORDINATE.first;
                int col = COORDINATE.second;
                groupRank[dsu.find(row)] = max({groupRank[dsu.find(row)], rowRank[row], colRank[col]});
            }
            
            for(const pair<int, int>& COORDINATE: COORDINATES){
                int row = COORDINATE.first;
                int col = COORDINATE.second;
                int newGroupRank = 1 + groupRank[dsu.find(row)];
                rowRank[row] = newGroupRank;
                colRank[col] = newGroupRank;
                answer[row][col] = newGroupRank;
            }
        }
        
        return answer;
    }
};