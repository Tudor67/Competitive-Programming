class Solution {
private:
    static bool isInside(int row, int col, const int& R, const int& C){
        return (0 <= row && row < R && 0 <= col && col < C);
    }
    
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> coordinates;
        coordinates.push_back({r0, c0});
        int row = r0;
        int col = c0;
        int len = 1;
        while(coordinates.size() < R * C){
            for(int step = 1; step <= len; ++step){
                if(isInside(row, col + step, R, C)){
                    coordinates.push_back({row, col + step});
                }
            }
            col += len;
            for(int step = 1; step <= len; ++step){
                if(isInside(row + step, col, R, C)){
                    coordinates.push_back({row + step, col});
                }
            }
            row += len;
            len += 1;
            for(int step = 1; step <= len; ++step){
                if(isInside(row, col - step, R, C)){
                    coordinates.push_back({row, col - step});
                }
            }
            col -= len;
            for(int step = 1; step <= len; ++step){
                if(isInside(row - step, col, R, C)){
                    coordinates.push_back({row - step, col});
                }
            }
            row -= len;
            len += 1;
        }
        return coordinates;
    }
};