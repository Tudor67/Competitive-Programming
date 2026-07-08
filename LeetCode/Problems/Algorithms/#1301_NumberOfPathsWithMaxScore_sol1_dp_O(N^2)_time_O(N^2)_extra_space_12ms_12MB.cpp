class Solution {
private:
    bool isInside(int i, int j, vector<vector<int>>& mat){
        const int N = mat.size();
        return (0 <= i && i < N && 0 <= j && j < N);
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int N = board.size();
        const int MODULO = 1'000'000'007;
        const int INF = 1e9;
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 1}, {1, 0}};

        // maxSum[i][j]: max sum of a valid path from (N - 1, N - 1) to (i, j)
        // count[i][j]: the count of valid paths from (N - 1, N - 1) to (i, j)
        //              with sum equal to maxSum[i][j]
        vector<vector<int>> maxSum(N, vector<int>(N, -INF));
        vector<vector<int>> count(N, vector<int>(N));

        for(int i = N - 1; i >= 0; --i){
            for(int j = N - 1; j >= 0; --j){
                if(i == N - 1 && j == N - 1){
                    maxSum[i][j] = 0;
                    count[i][j] = 1;
                }else if(isdigit(board[i][j]) || board[i][j] == 'E'){
                    int neighMaxSum = -INF;
                    for(auto [iDir, jDir]: DIRECTIONS){
                        int neighI = i + iDir;
                        int neighJ = j + jDir;
                        if(isInside(neighI, neighJ, maxSum)){
                            neighMaxSum = max(neighMaxSum, maxSum[neighI][neighJ]);
                        }
                    }

                    if(neighMaxSum != -INF){
                        int cellDigit = isdigit(board[i][j]) ? (board[i][j] - '0') : 0;
                        maxSum[i][j] = cellDigit + neighMaxSum;
                        count[i][j] = 0;
                        for(auto [iDir, jDir]: DIRECTIONS){
                            int neighI = i + iDir;
                            int neighJ = j + jDir;
                            if(isInside(neighI, neighJ, maxSum) && maxSum[i][j] == cellDigit + maxSum[neighI][neighJ]){
                                count[i][j] = (count[i][j] + count[neighI][neighJ]) % MODULO;
                            }
                        }
                    }
                }
            }
        }

        return {max(0, maxSum[0][0]), count[0][0]};
    }
};