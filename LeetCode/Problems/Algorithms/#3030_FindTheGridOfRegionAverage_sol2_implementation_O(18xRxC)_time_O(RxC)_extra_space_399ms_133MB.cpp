class Solution {
private:
    pair<int, int> computeRegMaxAdjDiffAndSum(vector<vector<int>>& image, int startRow, int startCol){
        int maxDiff = 0;
        int sum = 0;
        for(int row = startRow; row < startRow + 3; ++row){
            for(int col = startCol; col < startCol + 3; ++col){
                if(row + 1 < startRow + 3){
                    maxDiff = max(maxDiff, abs(image[row][col] - image[row + 1][col]));
                }
                if(col + 1 < startCol + 3){
                    maxDiff = max(maxDiff, abs(image[row][col] - image[row][col + 1]));
                }
                sum += image[row][col];
            }
        }
        return {maxDiff, sum};
    }
    
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        const int ROWS = image.size();
        const int COLS = image[0].size();
        
        vector<vector<int>> sum(ROWS, vector<int>(COLS));
        vector<vector<int>> count(ROWS, vector<int>(COLS));
        for(int row = 0; row + 2 < ROWS; ++row){
            for(int col = 0; col + 2 < COLS; ++col){
                pair<int, int> regMaxAdjDiffAndSum = computeRegMaxAdjDiffAndSum(image, row, col);
                if(regMaxAdjDiffAndSum.first <= threshold){
                    for(int i = 0; i < 3; ++i){
                        for(int j = 0; j < 3; ++j){
                            sum[row + i][col + j] += regMaxAdjDiffAndSum.second / 9;
                            count[row + i][col + j] += 1;
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> res = image;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(count[row][col] >= 1){
                    res[row][col] = sum[row][col] / count[row][col];
                }
            }
        }
        
        return res;
    }
};