class Solution {
public:
    int trapRainWater(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        const int INF = 1e9;
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        vector<vector<int>> maxValidHeights(ROWS, vector<int>(COLS, INF));
        using T3 = tuple<int, int, int>;
        priority_queue<T3, vector<T3>, greater<T3>> minHeap;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0 || row == ROWS - 1 || col == 0 || col == COLS - 1){
                    maxValidHeights[row][col] = heights[row][col];
                    minHeap.push({maxValidHeights[row][col], row, col});
                }
            }
        }

        int res = 0;
        while(!minHeap.empty()){
            int row = get<1>(minHeap.top());
            int col = get<2>(minHeap.top());
            minHeap.pop();

            res += (maxValidHeights[row][col] - heights[row][col]);

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
                   maxValidHeights[nextRow][nextCol] == INF){
                    maxValidHeights[nextRow][nextCol] = max(heights[nextRow][nextCol],
                                                            maxValidHeights[row][col]);
                    minHeap.push({maxValidHeights[nextRow][nextCol], nextRow, nextCol});
                }
            }
        }

        return res;
    }
};