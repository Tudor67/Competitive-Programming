class Solution {
private:
    void dfs(int row, int col, set<pair<int, int>>& vis,
             map<int, vector<pair<int, int>>>& stonesAtRow,
             map<int, vector<pair<int, int>>>& stonesAtCol){
        if(vis.count({row, col})){
            return;
        }
        
        vis.insert({row, col});
        
        for(vector<pair<int, int>>* stones: {&stonesAtRow[row], &stonesAtCol[col]}){
            for(const pair<int, int>& STONE: *stones){
                int nextRow = STONE.first;
                int nextCol = STONE.second;
                dfs(nextRow, nextCol, vis, stonesAtRow, stonesAtCol);
            }
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        map<int, vector<pair<int, int>>> stonesAtRow;
        map<int, vector<pair<int, int>>> stonesAtCol;
        for(const vector<int>& STONE: stones){
            int row = STONE[0];
            int col = STONE[1];
            stonesAtRow[row].push_back({row, col});
            stonesAtCol[col].push_back({row, col});
        }
        
        int connectedComponents = 0;
        set<pair<int, int>> vis;
        for(const vector<int>& STONE: stones){
            int row = STONE[0];
            int col = STONE[1];
            if(!vis.count({row, col})){
                connectedComponents += 1;
                dfs(row, col, vis, stonesAtRow, stonesAtCol);
            }
        }
        
        return (int)stones.size() - connectedComponents;
    }
};