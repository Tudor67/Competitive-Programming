class Solution {
private:
    using Matrix2D = vector<vector<int>>;
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void initGroupIdx(Matrix2D& groupIdx){
        const int ROWS = groupIdx.size();
        const int COLS = groupIdx[0].size();
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0 || row == ROWS - 1 || col == 0 || col == COLS - 1){
                    groupIdx[row][col] = 1;
                }else{
                    groupIdx[row][col] = 0;
                }
            }
        }
    }
    
    void groupNeighborsWithEqualHeight(const Matrix2D& HEIGHT_MAP, const int& ROW, const int& COL,
                                       Matrix2D& groupIdx, const int& CURRENT_GROUP_IDX){
        queue<pair<int, int>> q;
        q.push({ROW, COL});
        groupIdx[ROW][COL] = CURRENT_GROUP_IDX;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(groupIdx[nextRow][nextCol] == 0 &&
                   HEIGHT_MAP[nextRow][nextCol] == HEIGHT_MAP[ROW][COL]){
                    groupIdx[nextRow][nextCol] = CURRENT_GROUP_IDX;
                    q.push({nextRow, nextCol});
                }
            }
        }
    }
    
    int getGroupMinNeighborHeight(const Matrix2D& HEIGHT_MAP, const int& ROW, const int& COL,
                                  Matrix2D& groupIdx, const int& CURRENT_GROUP_IDX){
        int minNeighborHeight = INT_MAX;
        queue<pair<int, int>> q;
        q.push({ROW, COL});
        groupIdx[ROW][COL] = -CURRENT_GROUP_IDX; // mark as visited
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(groupIdx[nextRow][nextCol] == CURRENT_GROUP_IDX){
                    groupIdx[nextRow][nextCol] = -CURRENT_GROUP_IDX; // mark as visited
                    q.push({nextRow, nextCol});
                }else if(abs(groupIdx[nextRow][nextCol]) != CURRENT_GROUP_IDX){
                    minNeighborHeight = min(HEIGHT_MAP[nextRow][nextCol], minNeighborHeight);
                }
            }
        }
        
        return minNeighborHeight;
    }
    
    void updateAnswerAndHeightMap(Matrix2D& heightMap, const int& ROW, const int& COL,
                                  Matrix2D& groupIdx, const int& CURRENT_GROUP_IDX,
                                  const int& MIN_NEIGHBOR_HEIGHT,
                                  int& answer){
        queue<pair<int, int>> q;
        q.push({ROW, COL});
        groupIdx[ROW][COL] = CURRENT_GROUP_IDX; // mark as visited
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int trappedWater = max(0, MIN_NEIGHBOR_HEIGHT - heightMap[row][col]);
            if(trappedWater > 0){
                answer += trappedWater;
                heightMap[row][col] = MIN_NEIGHBOR_HEIGHT;
            }
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(groupIdx[nextRow][nextCol] == -CURRENT_GROUP_IDX){
                    groupIdx[nextRow][nextCol] = CURRENT_GROUP_IDX; // mark as visited
                    q.push({nextRow, nextCol});
                }
            }
        }
    }
    
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int ROWS = heightMap.size();
        const int COLS = heightMap[0].size();
        
        int prevAnswer = -1;
        int answer = 0;
        Matrix2D groupIdx(ROWS, vector<int>(COLS));
        while(prevAnswer != answer){
            prevAnswer = answer;
            initGroupIdx(groupIdx);
            int currentGroupIdx = 1;
            for(int row = 1; row < ROWS - 1; ++row){
                for(int col = 1; col < COLS - 1; ++col){
                    if(groupIdx[row][col] == 0){
                        currentGroupIdx += 1;
                        groupNeighborsWithEqualHeight(heightMap, row, col, groupIdx, currentGroupIdx);
                        int minNeighborHeight = getGroupMinNeighborHeight(heightMap, row, col, groupIdx, currentGroupIdx);
                        updateAnswerAndHeightMap(heightMap, row, col, groupIdx, currentGroupIdx, minNeighborHeight, answer);
                    }
                }
            }
        }
        
        return answer;
    }
};