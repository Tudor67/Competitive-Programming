class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        const int N = boxes.size();
        const int INF = 1e8;
        
        // prefWeight[i]: prefix sum of boxes weights: boxes[0][1] + boxes[1][1] + ... + boxes[i][1]
        vector<long long> prefWeight(N);
        prefWeight[0] = boxes[0][1];
        for(int i = 1; i < N; ++i){
            prefWeight[i] = prefWeight[i - 1] + boxes[i][1];
        }
        
        // prefConsMismatches[i]: prefix sum of consecutive port mismatches in boxes[0 .. i]
        vector<int> prefConsMismatches(N);
        prefConsMismatches[0] = 0;
        for(int i = 1; i < N; ++i){
            prefConsMismatches[i] = prefConsMismatches[i - 1] + (boxes[i - 1][0] != boxes[i][0]);
        }
        
        // dp[i]: min number of trips to deliver boxes[0 ... i]
        vector<int> dp(N, INF);
        dp[0] = 2;
        for(int i = 1; i < N; ++i){
            // binary search 1: find max [j .. i] range of boxes that can be delivered without going to storage
            // goal: to minimize leftCost
            int l = 0;
            int r = i;
            while(l != r){
                int mid = (l + r) / 2;
                int rightBoxes = i - mid + 1;
                long long rightWeight = prefWeight[i] - (mid >= 1 ? prefWeight[mid - 1] : 0);
                if(rightBoxes <= maxBoxes && rightWeight <= maxWeight){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            int j = r;
            int rightBoxes = i - j + 1;
            long long rightWeight = prefWeight[i] - (j >= 1 ? prefWeight[j - 1] : 0);
            if(rightBoxes <= maxBoxes && rightWeight <= maxWeight){
                // binary search 2: choose rightmost dp[k] such that dp[k] == dp[j - 1]
                // goal: to minimize rightCost (leftCost is fixed)
                int val = (j >= 1 ? dp[j - 1] : 0);
                int l = j - 1;
                int r = i - 1;
                while(l != r){
                    int mid = (l + r + 1) / 2;
                    if(val == dp[mid]){
                        l = mid;
                    }else{
                        r = mid - 1;
                    }
                }
                j = r + 1;
                int leftCost = (j >= 1 ? dp[j - 1] : 0);
                int rightCost = prefConsMismatches[i] - prefConsMismatches[j] + 2;
                // deliver boxes[0 .. j - 1] and go to storage + deliver boxes[j .. i] without going to storage + go to storage
                dp[i] = min(leftCost + rightCost, dp[i]);
            }
        }
        
        return dp[N - 1];
    }
};