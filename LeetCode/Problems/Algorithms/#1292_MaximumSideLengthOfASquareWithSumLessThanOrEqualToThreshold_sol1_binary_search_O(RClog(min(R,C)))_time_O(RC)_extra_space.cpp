class Solution {
private:
    vector<vector<int>> computePrefSum(vector<vector<int>>& mat, const int& ROWS, const int& COLS){
        vector<vector<int>> prefSum = mat;
        for(int col = 1; col < COLS; ++col){
            prefSum[0][col] += prefSum[0][col - 1];
        }
        for(int row = 1; row < ROWS; ++row){
            prefSum[row][0] += prefSum[row - 1][0];
        }
        for(int row = 1; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                prefSum[row][col] += prefSum[row - 1][col] + prefSum[row][col - 1] - prefSum[row - 1][col - 1];
            }
        }
        return prefSum;
    }
    
    int sumOfSquare(int row1, int col1, int row2, int col2, vector<vector<int>>& prefSum){
        int sum = 0;
        sum += prefSum[row2][col2];
        if(row1 >= 1){
            sum -= prefSum[row1 - 1][col2];
        }
        if(col1 >= 1){
            sum -= prefSum[row2][col1 - 1];
        }
        if(row1 >= 1 && col1 >= 1){
            sum += prefSum[row1 - 1][col1 - 1];
        }
        return sum;
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        
        // prefix sum
        vector<vector<int>> prefSum = computePrefSum(mat, ROWS, COLS);
        
        int answer = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int l = answer;
                int r = min(ROWS - row, COLS - col);
                if(l < r){
                    // binary search
                    while(l != r){
                        int mid = (l + r + 1) / 2;
                        if(sumOfSquare(row, col, row + mid - 1, col + mid - 1, prefSum) <= threshold){
                            l = mid;
                        }else{
                            r = mid - 1;
                        }
                    }
                }
                answer = max(r, answer);
            }
        }
        
        return answer;
    }
};