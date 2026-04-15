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

        // dp[i][ffc]: min distance for word[i .. N - 1]
        //             when the current finger is implicitly at word[i + 1]
        //             and the free finger is at ('A' + ffc - 1)
        vector<vector<int>> dp(N + 1, vector<int>(A));

        for(int i = N - 1; i >= 0; --i){
            int currCharIdx = word[i] - 'A';
            int nextCharIdx = (i == N - 1 ? currCharIdx : word[i + 1] - 'A');

            fill(dp[i].begin(), dp[i].end(), INF);

            for(int ffc = 0; ffc < A; ++ffc){
                // option 1: use the current finger
                //           free finger stays at ffc
                minimize(dp[i][ffc], dist[currCharIdx][nextCharIdx] + dp[i + 1][ffc]);

                // option 2: use the free finger
                //           free finger becomes the previous active finger (at nextCharIdx)
                minimize(dp[i][nextCharIdx], dist[currCharIdx][ffc] + dp[i + 1][ffc]);
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};