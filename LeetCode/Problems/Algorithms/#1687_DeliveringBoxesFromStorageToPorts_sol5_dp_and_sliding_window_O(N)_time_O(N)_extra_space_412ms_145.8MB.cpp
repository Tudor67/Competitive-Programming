class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        const int N = boxes.size();
        const int INF = 1e8;
        
        // dp[i]: min number of trips to deliver boxes[0 ... i]
        vector<int> dp(N, INF);
        dp[0] = 2;
        int j = 0;
        int rightBoxes = 1;
        int rightWeight = boxes[j][1];
        int rightCost = 2;
        for(int i = 1; i < N; ++i){
            rightBoxes += 1;
            rightWeight += boxes[i][1];
            rightCost += (boxes[i - 1][0] != boxes[i][0]);
            // 1.) find max [j .. i] range of boxes that can be delivered without going to storage
            // goal: to minimize leftCost
            while(rightBoxes > maxBoxes || rightWeight > maxWeight){
                rightBoxes -= 1;
                rightWeight -= boxes[j][1];
                rightCost -= (boxes[j][0] != boxes[j + 1][0]);
                j += 1;
            }
            // 2.) choose rightmost dp[k] such that dp[k] == dp[j - 1]
            // goal: to minimize rightCost (leftCost is fixed)
            while(j >= 1 && dp[j - 1] == dp[j]){
                rightBoxes -= 1;
                rightWeight -= boxes[j][1];
                rightCost -= (boxes[j][0] != boxes[j + 1][0]);
                j += 1;
            }
            // deliver boxes[0 .. j - 1] and go to storage + deliver boxes[j .. i] without going to storage + go to storage
            int leftCost = (j >= 1 ? dp[j - 1] : 0);
            dp[i] = min(leftCost + rightCost, dp[i]);
        }
        
        return dp[N - 1];
    }
};