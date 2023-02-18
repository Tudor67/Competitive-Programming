class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = k + N;

        // dp[j]: current min cost of a good split for nums[0 .. j]
        vector<int> dp(N, INF);
        unordered_map<int, int> count;

        for(int i = 0; i < N; ++i){
            int dpPrev = (i == 0 ? 0 : dp[i - 1]);
            int importanceValue = k;
            count.clear();

            for(int j = i; j < N; ++j){
                count[nums[j]] += 1;
                if(count[nums[j]] == 2){
                    importanceValue += 2;
                }else if(count[nums[j]] >= 3){
                    importanceValue += 1;
                }
                dp[j] = min(dp[j], dpPrev + importanceValue);
            }
        }

        return dp[N - 1];
    }
};