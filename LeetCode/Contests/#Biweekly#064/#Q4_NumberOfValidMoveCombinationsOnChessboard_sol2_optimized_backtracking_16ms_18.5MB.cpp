class Solution {
private:
    const unordered_map<string, vector<pair<int, int>>> DIRECTIONS_OF = {
        {"rook", {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}},
        {"bishop", {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}},
        {"queen", {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}
    };
    const int INF = 1e8;
    
    bool isInsideBoard(int row, int col){
        return (0 <= row && row < 8 && 0 <= col && col < 8);
    }
    
    bool isVisitedTime(int t, int timeMask){
        return ((timeMask >> t) & 1);
    }
    
    int getMaxTime(int timeMask){
        if(timeMask > 0){
            return 31 - __builtin_clz((unsigned int)timeMask);
        }
        return 0;
    }
    
    void dfs(int level, const int& N, const vector<vector<int>>& POSITIONS, const vector<vector<pair<int, int>>>& DIRECTIONS,
             vector<vector<int>>& timeMasks, vector<vector<int>>& blockTime, int& validMoveCombinations){
        if(level == N){
            validMoveCombinations += 1;
        }else{
            int row = POSITIONS[level][0];
            int col = POSITIONS[level][1];
            
            timeMasks[row][col] += 1;
            if(getMaxTime(timeMasks[row][col]) == 0 && blockTime[row][col] == INF){
                blockTime[row][col] = 0;
                dfs(level + 1, N, POSITIONS, DIRECTIONS, timeMasks, blockTime, validMoveCombinations);
                blockTime[row][col] = INF;
            }
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS[level]){
                int lastUpdatedT = 0;
                for(int t = 1; t < 8; ++t){
                    int nextRow = row + t * DIRECTION.first;
                    int nextCol = col + t * DIRECTION.second;
                    if(isInsideBoard(nextRow, nextCol)){
                        if(!isVisitedTime(t, timeMasks[nextRow][nextCol]) && t < blockTime[nextRow][nextCol]){
                            int maxTime = getMaxTime(timeMasks[nextRow][nextCol]);
                            timeMasks[nextRow][nextCol] += (1 << t);
                            lastUpdatedT = t;
                            if(maxTime < t){
                                blockTime[nextRow][nextCol] = t;
                                dfs(level + 1, N, POSITIONS, DIRECTIONS, timeMasks, blockTime, validMoveCombinations);
                                blockTime[nextRow][nextCol] = INF;
                            }
                        }else{
                            break;
                        }
                    }else{
                        break;
                    }
                }
                
                for(int t = 1; t <= lastUpdatedT; ++t){
                    int nextRow = row + t * DIRECTION.first;
                    int nextCol = col + t * DIRECTION.second;
                    timeMasks[nextRow][nextCol] -= (1 << t);
                }
            }
            
            timeMasks[row][col] -= 1;
        }
    }
    
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        const int N = pieces.size();
        
        vector<vector<pair<int, int>>> directions(N);
        for(int i = 0; i < N; ++i){
            directions[i] = DIRECTIONS_OF.at(pieces[i]);
            positions[i][0] -= 1;
            positions[i][1] -= 1;
        }
        
        int validMoveCombinations = 0;
        vector<vector<int>> timeMasks(8, vector<int>(8, 0));
        vector<vector<int>> blockTime(8, vector<int>(8, INF));
        dfs(0, N, positions, directions, timeMasks, blockTime, validMoveCombinations);
        
        return validMoveCombinations;
    }
};