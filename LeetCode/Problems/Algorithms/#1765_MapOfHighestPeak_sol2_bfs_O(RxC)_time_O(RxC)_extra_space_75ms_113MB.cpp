class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int ROWS = isWater.size();
        const int COLS = isWater[0].size();
        const int INF = 1e9;
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        vector<vector<int>> maxHeight(ROWS, vector<int>(COLS));
        queue<pair<int, int>> q;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(isWater[row][col]){
                    maxHeight[row][col] = 0;
                    q.push({row, col});
                }else{
                    maxHeight[row][col] = INF;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
                   maxHeight[nextRow][nextCol] == INF){
                    maxHeight[nextRow][nextCol] = 1 + maxHeight[row][col];
                    q.push({nextRow, nextCol});
                }
            }
        }

        return maxHeight;
    }
};