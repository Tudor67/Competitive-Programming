class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();

        vector<vector<pair<int, int>>> v(ROWS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                v[row].push_back({board[row][col], col});
            }
            sort(v[row].rbegin(), v[row].rend());
            v[row].resize(3);
        }

        long long maxSum = LLONG_MIN / 10;
        for(int row1 = 0; row1 < ROWS; ++row1){
            for(int row2 = row1 + 1; row2 < ROWS; ++row2){
                for(int row3 = row2 + 1; row3 < ROWS; ++row3){
                    for(auto [val1, col1]: v[row1]){
                        for(auto [val2, col2]: v[row2]){
                            for(auto [val3, col3]: v[row3]){
                                if(col1 != col2 && col1 != col3 && col2 != col3){
                                    maxSum = max(maxSum, val1 + (long long)val2 + val3);
                                }
                            }
                        }
                    }
                }
            }
        }

        return maxSum;
    }
};