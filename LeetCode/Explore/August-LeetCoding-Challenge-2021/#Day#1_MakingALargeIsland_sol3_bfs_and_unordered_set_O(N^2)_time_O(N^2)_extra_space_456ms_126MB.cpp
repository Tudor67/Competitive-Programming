class Solution {
private:
    int getIdx(int row, int col, const int& N){
        return (row * N + col);
    }
    
    void bfs(const int& ROW, const int& COL, const int& N, vector<vector<int>>& groupIdx, const int& CURRENT_GROUP_IDX){
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        if(groupIdx[ROW][COL] == 0){
            groupIdx[ROW][COL] = CURRENT_GROUP_IDX;
            q.push({ROW, COL});
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int neighRow = row + DIRECTION.first;
                int neighCol = col + DIRECTION.second;
                if(0 <= neighRow && neighRow < N && 0 <= neighCol && neighCol < N && groupIdx[neighRow][neighCol] == 0){
                    groupIdx[neighRow][neighCol] = CURRENT_GROUP_IDX;
                    q.push({neighRow, neighCol});
                }
            }
        }
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        vector<vector<int>> groupIdx(N, vector<int>(N));
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] == 0){
                    groupIdx[row][col] = -1;
                }else{
                    groupIdx[row][col] = 0;
                }
            }
        }
        
        int currentGroupIdx = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(groupIdx[row][col] == 0){
                    currentGroupIdx += 1;
                    bfs(row, col, N, groupIdx, currentGroupIdx);
                }
            }
        }
        
        unordered_map<int, int> groupSize;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] == 1){
                    groupSize[groupIdx[row][col]] += 1;
                }
            }
        }
        
        int maxAchievableGroupSize = 0;
        for(const pair<int, int>& P: groupSize){
            maxAchievableGroupSize = max(maxAchievableGroupSize, P.second);
        }
        
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        unordered_set<int> neighGroups;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] == 0){
                    neighGroups.clear();
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int neighRow = row + DIRECTION.first;
                        int neighCol = col + DIRECTION.second;
                        if(0 <= neighRow && neighRow < N && 0 <= neighCol && neighCol < N && grid[neighRow][neighCol] == 1){
                            neighGroups.insert(groupIdx[neighRow][neighCol]);
                        }
                    }
                    int neighGroupsTotalSize = 1;
                    for(int neighGroup: neighGroups){
                        neighGroupsTotalSize += groupSize[neighGroup];
                    }
                    maxAchievableGroupSize = max(maxAchievableGroupSize, neighGroupsTotalSize);
                }
            }
        }
        
        return maxAchievableGroupSize;
    }
};