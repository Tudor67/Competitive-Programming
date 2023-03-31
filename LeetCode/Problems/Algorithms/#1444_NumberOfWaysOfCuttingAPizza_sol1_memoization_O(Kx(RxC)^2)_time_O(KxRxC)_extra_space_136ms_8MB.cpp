class Solution {
private:
    static const char APPLE = 'A';
    static const int MODULO = 1e9 + 7;

    int countApples(vector<string>& pizza, int row1, int col1, int row2, int col2){
        int apples = 0;
        for(int row = row1; row <= row2; ++row){
            for(int col = col1; col <= col2; ++col){
                apples += (int)(pizza[row][col] == APPLE);
            }
        }
        return apples;
    }

    int ways(vector<string>& pizza, int k, int startRow, int startCol, vector<vector<vector<int>>>& memo){
        const int ROWS = pizza.size();
        const int COLS = pizza[0].size();

        int res = 0;
        if(memo[k][startRow][startCol] != -1){
            res = memo[k][startRow][startCol];
        }else if(k == 1){
            // base case
            int apples = countApples(pizza, startRow, startCol, ROWS - 1, COLS - 1);
            if(apples >= 1){
                res = 1;
            }
        }else if(startRow >= ROWS - 1 && startCol >= COLS - 1){
            // base case
            res = 0;
        }else{
            // horizontal cut
            int apples = 0;
            for(int row = startRow; row < ROWS - 1; ++row){
                apples += countApples(pizza, row, startCol, row, COLS - 1);
                if(apples >= 1){
                    res = (res + ways(pizza, k - 1, row + 1, startCol, memo)) % MODULO;
                }
            }

            // vertical cut
            apples = 0;
            for(int col = startCol; col < COLS - 1; ++col){
                apples += countApples(pizza, startRow, col, ROWS - 1, col);
                if(apples >= 1){
                    res = (res + ways(pizza, k - 1, startRow, col + 1, memo)) % MODULO;
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
        vector<vector<vector<int>>> memo(k + 1, vector<vector<int>>(ROWS, vector<int>(COLS, -1)));
        return ways(pizza, k, 0, 0, memo);
    }
};