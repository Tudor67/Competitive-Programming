class Solution {
private:
    static const char APPLE = 'A';
    static const int MODULO = 1e9 + 7;

    int countApples(vector<vector<int>>& applesPrefSum, int row1, int col1, int row2, int col2){
        int apples = applesPrefSum[row2][col2];
        if(row1 >= 1){
            apples -= applesPrefSum[row1 - 1][col2];
        }
        if(col1 >= 1){
            apples -= applesPrefSum[row2][col1 - 1];
        }
        if(row1 >= 1 && col1 >= 1){
            apples += applesPrefSum[row1 - 1][col1 - 1];
        }
        return apples;
    }

    int ways(vector<string>& pizza, vector<vector<int>>& applesPrefSum,
             int k, int startRow, int startCol, vector<vector<vector<int>>>& memo){
        const int ROWS = pizza.size();
        const int COLS = pizza[0].size();

        int res = 0;
        if(memo[k][startRow][startCol] != -1){
            res = memo[k][startRow][startCol];
        }else if(k == 1){
            // base case
            int apples = countApples(applesPrefSum, startRow, startCol, ROWS - 1, COLS - 1);
            if(apples >= 1){
                res = 1;
            }
        }else if(startRow >= ROWS - 1 && startCol >= COLS - 1){
            // base case
            res = 0;
        }else{
            // horizontal cut
            for(int row = startRow; row < ROWS - 1; ++row){
                int apples = countApples(applesPrefSum, startRow, startCol, row, COLS - 1);
                if(apples >= 1){
                    res = (res + ways(pizza, applesPrefSum, k - 1, row + 1, startCol, memo)) % MODULO;
                }
            }

            // vertical cut
            for(int col = startCol; col < COLS - 1; ++col){
                int apples = countApples(applesPrefSum, startRow, startCol, ROWS - 1, col);
                if(apples >= 1){
                    res = (res + ways(pizza, applesPrefSum, k - 1, startRow, col + 1, memo)) % MODULO;
                }
            }
        }

        memo[k][startRow][startCol] = res;
        return memo[k][startRow][startCol];
    }

public:
    int ways(vector<string>& pizza, int k) {
        const int ROWS = pizza.size();
        const int COLS = pizza[0].size();

        vector<vector<int>> applesPrefSum(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                applesPrefSum[row][col] = (int)(pizza[row][col] == APPLE);
                if(row >= 1){
                    applesPrefSum[row][col] += applesPrefSum[row - 1][col];
                }
                if(col >= 1){
                    applesPrefSum[row][col] += applesPrefSum[row][col - 1];
                }
                if(row >= 1 && col >= 1){
                    applesPrefSum[row][col] -= applesPrefSum[row - 1][col - 1];
                }
            }
        }

        vector<vector<vector<int>>> memo(k + 1, vector<vector<int>>(ROWS, vector<int>(COLS, -1)));
        return ways(pizza, applesPrefSum, k, 0, 0, memo);
    }
};