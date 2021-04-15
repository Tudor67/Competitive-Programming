class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const vector<pair<int, int>> DIRECTIONS = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<vector<int>> dist(ROWS, vector<int>(COLS, 1));
        set<tuple<int, int, int>> tupleSet;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                tupleSet.insert({matrix[row][col], row, col});
            }
        }
        
        while(!tupleSet.empty()){
            int row = get<1>(*prev(tupleSet.end()));
            int col = get<2>(*prev(tupleSet.end()));
            tupleSet.erase(prev(tupleSet.end()));
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
                   matrix[nextRow][nextCol] < matrix[row][col] && dist[nextRow][nextCol] < 1 + dist[row][col]){
                    dist[nextRow][nextCol] = 1 + dist[row][col];
                    tupleSet.insert({matrix[nextRow][nextCol], nextRow, nextCol});
                }
            }
        }
        
        int answer = 1;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                answer = max(dist[row][col], answer);
            }
        }
        
        return answer;
    }
};