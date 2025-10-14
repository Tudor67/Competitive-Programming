class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int ROWS = heightMap.size();
        const int COLS = heightMap[0].size();
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int INF = 1e9;

        using State = array<int, 3>;
        priority_queue<State, vector<State>, greater<State>> statesMinHeap;
        vector<vector<int>> maxValidHeight(ROWS, vector<int>(COLS, INF));

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0 || row == ROWS - 1 || col == 0 || col == COLS - 1){
                    maxValidHeight[row][col] = heightMap[row][col];
                    statesMinHeap.push({maxValidHeight[row][col], row, col});
                }
            }
        }

        int totalWater = 0;
        while(!statesMinHeap.empty()){
            int row = statesMinHeap.top()[1];
            int col = statesMinHeap.top()[2];
            statesMinHeap.pop();

            totalWater += (maxValidHeight[row][col] - heightMap[row][col]);

            for(auto [rowDir, colDir]: DIRECTIONS){
                int nextRow = row + rowDir;
                int nextCol = col + colDir;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
                   maxValidHeight[nextRow][nextCol] == INF){
                    maxValidHeight[nextRow][nextCol] = max(maxValidHeight[row][col], heightMap[nextRow][nextCol]);
                    statesMinHeap.push({maxValidHeight[nextRow][nextCol], nextRow, nextCol});
                }
            }
        }
        
        return totalWater;
    }
};