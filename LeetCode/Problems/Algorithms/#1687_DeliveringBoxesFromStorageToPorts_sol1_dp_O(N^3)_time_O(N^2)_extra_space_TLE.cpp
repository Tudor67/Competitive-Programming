class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        const int N = boxes.size();
        const int INF = 1e8;
        
        // dp[i][len]: min number of trips to deliver boxes[i ... i + len - 1]
        // weight[i][len]: weight of boxes[i ... i + len - 1]
        vector<vector<int>> dp(N, vector<int>(N + 1, INF));
        vector<vector<int>> weight(N, vector<int>(N + 1, 0));
        for(int i = 0; i <= N - 1; ++i){
            dp[i][1] = 2;
            weight[i][1] = boxes[i][1];
        }
        
        for(int len = 2; len <= N; ++len){
            for(int i = 0; i + len - 1 <= N - 1; ++i){
                weight[i][len] = weight[i][len - 1] + boxes[i + len - 1][1];
                for(int k = 1; k <= len - 1; ++k){
                    if(len <= maxBoxes && weight[i][len] <= maxWeight){
                        dp[i][len] = min(dp[i][k] + dp[i + k][len - k] - 1 - (boxes[i + k - 1][0] == boxes[i + k][0]), dp[i][len]);
                    }else{
                        dp[i][len] = min(dp[i][k] + dp[i + k][len - k], dp[i][len]);
                    }
                }
            }
        }
        
        return dp[0][N];
    }
};