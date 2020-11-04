class Solution {
    using Cell = tuple<int, int, int>;
    
    struct MinHeapCellComparator{
        bool operator()(const Cell& LHS, const Cell& RHS){
            return (get<0>(LHS) > get<0>(RHS));
        }
    };
    
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int ROWS = heightMap.size();
        const int COLS = heightMap[0].size();
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        priority_queue<Cell, vector<Cell>, MinHeapCellComparator> minHeap;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0 || row == ROWS - 1 || col == 0 || col == COLS - 1){
                    minHeap.push({heightMap[row][col], row, col});
                    vis[row][col] = true;
                }
            }
        }
        
        int answer = 0;
        while(!minHeap.empty()){
            Cell cell = minHeap.top();
            int height = get<0>(cell);
            int row = get<1>(cell);
            int col = get<2>(cell);
            minHeap.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && !vis[nextRow][nextCol]){
                    int nextHeight = heightMap[nextRow][nextCol];
                    answer += max(0, height - nextHeight);
                    minHeap.push({max(height, nextHeight), nextRow, nextCol});
                    vis[nextRow][nextCol] = true;
                }
            }
        }
        
        return answer;
    }
};