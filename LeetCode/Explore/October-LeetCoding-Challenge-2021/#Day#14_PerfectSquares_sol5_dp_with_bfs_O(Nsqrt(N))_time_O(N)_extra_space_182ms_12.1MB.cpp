class Solution {
public:
    int numSquares(int N) {
        // dp[i]: least number of perfect square numbers that sum to i
        vector<int> dp(N + 1, N + 1);
        queue<int> q;
        q.push(0);
        dp[0] = 0;
        while(!q.empty()){
            for(int step = q.size(); step >= 1; --step){
                int i = q.front();
                q.pop();
                for(int j = 1; i + j * j <= N; ++j){
                    if(dp[i] + 1 < dp[i + j * j]){
                        dp[i + j * j] = dp[i] + 1;
                        q.push(i + j * j);
                    }
                }
            }
        }
        return dp[N];
    }
};