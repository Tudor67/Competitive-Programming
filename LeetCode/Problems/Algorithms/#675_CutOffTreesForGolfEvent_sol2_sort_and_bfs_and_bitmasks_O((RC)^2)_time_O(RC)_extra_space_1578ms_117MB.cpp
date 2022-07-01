class Solution {
private:
    const int INF = 1e9;
    
    int computeDistance(int srcRow, int srcCol, int destRow, int destCol,
                        vector<vector<int>>& forest, vector<long long>& visMasks){
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        const int ROWS = forest.size();
        const int COLS = forest[0].size();
        
        for(int row = 0; row < ROWS; ++row){
            visMasks[row] = 0;
        }
        
        queue<pair<int, int>> q;
        q.emplace(srcRow, srcCol);
        visMasks[srcRow] |= (1LL << srcCol);
        
        int dist = -1;
        while(!q.empty()){
            dist += 1;
            for(int i = (int)q.size(); i >= 1; --i){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                if(row == destRow && col == destCol){
                    return dist;
                }
                
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                        if(((visMasks[nextRow] >> nextCol) & 1) == 0 && forest[nextRow][nextCol] >= 1){
                            visMasks[nextRow] |= (1LL << nextCol);
                            q.emplace(nextRow, nextCol);
                        }
                    }
                }
            }
        }
        
        return INF;
    }
    
public:
    int cutOffTree(vector<vector<int>>& forest) {
        const int ROWS = forest.size();
        const int COLS = forest[0].size();
        
        vector<tuple<int, int, int>> heightRowCol;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(forest[row][col] >= 2){
                    heightRowCol.emplace_back(forest[row][col], row, col);
                }
            }
        }
        
        sort(heightRowCol.begin(), heightRowCol.end());
        
        int res = 0;
        int prevRow = 0;
        int prevCol = 0;
        vector<long long> visMasks(ROWS);
        for(const tuple<int, int, int>& T: heightRowCol){
            int row = get<1>(T);
            int col = get<2>(T);
            int dist = computeDistance(prevRow, prevCol, row, col, forest, visMasks);
            if(dist == INF){
                res = -1;
                break;
            }else{
                res += dist;
                prevRow = row;
                prevCol = col;
            }
        }
        
        return res;
    }
};