class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();

        vector<array<int, 3>> v;
        v.reserve(ROWS * COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                v.push_back({board[row][col], row, col});
            }
        }

        sort(v.rbegin(), v.rend());

        const int SIZE = min(3 * (ROWS + COLS), (int)v.size());
        v.resize(SIZE);

        long long maxSum = LLONG_MIN / 10;
        for(int i = 0; i < SIZE; ++i){
            for(int j = i + 1; j < SIZE; ++j){
                for(int k = j + 1; k < SIZE; ++k){
                    if(v[i][1] != v[j][1] && v[i][1] != v[k][1] && v[j][1] != v[k][1] &&
                       v[i][2] != v[j][2] && v[i][2] != v[k][2] && v[j][2] != v[k][2]){
                        maxSum = max(maxSum, v[i][0] + (long long)v[j][0] + v[k][0]);
                        break;
                    }
                }
            }
        }

        return maxSum;
    }
};