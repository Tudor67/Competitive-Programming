class Solution {
private:
    void bfs(int srcRow, int srcCol, set<pair<int, int>>& vis,
             map<int, vector<pair<int, int>>>& stonesAtRow,
             map<int, vector<pair<int, int>>>& stonesAtCol){
        queue<pair<int, int>> q;
        if(!vis.count({srcRow, srcCol})){
            vis.insert({srcRow, srcCol});
            q.push({srcRow, srcCol});
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(vector<pair<int, int>>* stones: {&stonesAtRow[row], &stonesAtCol[col]}){
                for(const pair<int, int>& STONE: *stones){
                    int nextRow = STONE.first;
                    int nextCol = STONE.second;
                    if(!vis.count({nextRow, nextCol})){
                        vis.insert({nextRow, nextCol});
                        q.push({nextRow, nextCol});
                    }
                }
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
                bfs(row, col, vis, stonesAtRow, stonesAtCol);
            }
        }
        
        return (int)stones.size() - connectedComponents;
    }
};