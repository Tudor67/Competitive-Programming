class Solution {
private:
    static bool isInside(int row, int col, const int& R, const int& C){
        return (0 <= row && row < R && 0 <= col && col < C);
    }
    
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        const vector<pair<int, int>> STEP_SIGNS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const vector<int> LEN_CHANGE = {0, 1, 0, 1};
        vector<vector<int>> coordinates;
        coordinates.push_back({r0, c0});
        int row = r0;
        int col = c0;
        int len = 1;
        while(coordinates.size() < R * C){
            for(int i = 0; i < 4; ++i){
                for(int step = 1; step <= len; ++step){
                    int nextRow = row + STEP_SIGNS[i].first * step;
                    int nextCol = col + STEP_SIGNS[i].second * step;
                    if(isInside(nextRow, nextCol, R, C)){
                        coordinates.push_back({nextRow, nextCol});
                    }
                }
                row += STEP_SIGNS[i].first * len;
                col += STEP_SIGNS[i].second * len;
                len += LEN_CHANGE[i];
            }
        }
        return coordinates;
    }
};