class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        const int N = boxes.size();
        const int INF = 1e8;
        
        // dp[i]: min number of trips to deliver boxes[0 ... i]
        vector<int> dp(N, INF);
        dp[0] = 2;
        for(int i = 1; i < N; ++i){
            // deliver boxes[0 .. i - 1] and go to storage + deliver boxes[i] + go to storage
            dp[i] = dp[i - 1] + 2;
            int rightBoxes = 1;
            int rightWeight = boxes[i][1];
            int rightCost = 2;
            for(int j = i - 1; j >= 0; --j){
                rightBoxes += 1;
                rightWeight += boxes[j][1];
                rightCost += (boxes[j][0] != boxes[j + 1][0]);
                if(rightBoxes <= maxBoxes && rightWeight <= maxWeight){
                    int leftCost = 0;
                    if(j >= 1){
                        leftCost = dp[j - 1];
                    }
                    // deliver boxes[0 .. j - 1] and go to storage + deliver boxes[j .. i] without going to storage + go to storage
                    dp[i] = min(leftCost + rightCost, dp[i]);
                }else{
                    break;
                }
            }
        }
        
        return dp[N - 1];
    }
};