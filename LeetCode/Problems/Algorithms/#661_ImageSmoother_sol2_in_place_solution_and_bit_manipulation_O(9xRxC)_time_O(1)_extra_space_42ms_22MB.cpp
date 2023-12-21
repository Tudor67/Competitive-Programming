class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const int ROWS = img.size();
        const int COLS = img[0].size();
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int sum = 0;
                int count = 0;
                for(int dr = -1; dr <= 1; ++dr){
                    for(int dc = -1; dc <= 1; ++dc){
                        int neighRow = row + dr;
                        int neighCol = col + dc;
                        if(0 <= neighRow && neighRow < ROWS && 0 <= neighCol && neighCol < COLS){
                            sum += img[neighRow][neighCol] & ((1 << 8) - 1);
                            count += 1;
                        }
                    }
                }
                img[row][col] |= (sum / count) << 8;
            }
        }

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                img[row][col] >>= 8;
            }
        }

        return img;
    }
};