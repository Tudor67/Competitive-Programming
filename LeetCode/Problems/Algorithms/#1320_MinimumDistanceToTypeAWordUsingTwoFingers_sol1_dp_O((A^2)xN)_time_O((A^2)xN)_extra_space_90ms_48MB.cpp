class Solution {
private:
    void minimize(int& a, int b){
        a = min(a, b);
    }
    
public:
    int minimumDistance(string word) {
        const int N = word.length();
        const int A = 26;
        const int INF = 1e9;

        vector<vector<int>> dist(A, vector<int>(A));
        for(int i = 0; i < A; ++i){
            for(int j = 0; j < A; ++j){
                int iRow = i / 6;
                int iCol = i % 6;
                int jRow = j / 6;
                int jCol = j % 6;
                dist[i][j] = abs(iRow - jRow) + abs(iCol - jCol);
            }
        }

        // dp[i][a][b]: min distance for word[i .. N - 1]
        //              when the last char typed with the 1st finger is ('A' + a - 1) and
        //              when the last char typed with the 2nd finger is ('A' + b - 1)
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(A, vector<int>(A, INF)));
        for(int a = 0; a < A; ++a){
            for(int b = 0; b < A; ++b){
                dp[N][a][b] = 0;
            }
        }

        for(int i = N - 1; i >= 0; --i){
            int currCharIdx = word[i] - 'A';
            for(int a = 0; a < A; ++a){
                for(int b = 0; b < A; ++b){
                    minimize(dp[i][currCharIdx][b], dp[i + 1][a][b] + dist[currCharIdx][a]);
                    minimize(dp[i][a][currCharIdx], dp[i + 1][a][b] + dist[currCharIdx][b]);
                }
            }
        }

        int res = dp[0][0][0];
        for(int a = 0; a < A; ++a){
            for(int b = 0; b < A; ++b){
                res = min(res, dp[0][a][b]);
            }
        }

        return res;
    }
};