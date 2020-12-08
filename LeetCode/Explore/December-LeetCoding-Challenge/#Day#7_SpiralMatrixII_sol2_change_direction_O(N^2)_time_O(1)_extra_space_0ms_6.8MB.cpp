class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> a(n, vector<int>(n, 0));
        
        int row = 0;
        int col = 0;
        int dirIdx = 0;
        for(int val = 1; val <= n * n; ++val){
            a[row][col] = val;
            int nextRow = row + DIRECTIONS[dirIdx].first;
            int nextCol = col + DIRECTIONS[dirIdx].second;
            if(nextRow < 0 || n <= nextRow || nextCol < 0 || n <= nextCol || a[nextRow][nextCol] != 0){
                dirIdx = (dirIdx + 1) % 4;
                nextRow = row + DIRECTIONS[dirIdx].first;
                nextCol = col + DIRECTIONS[dirIdx].second;
            }
            row = nextRow;
            col = nextCol;
        }
        
        return a;
    }
};