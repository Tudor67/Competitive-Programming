class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int INF = k + N;

        // dp[j]: current min cost of a good split for nums[0 .. j]
        vector<int> dp(N, INF);
        vector<int> count(MAX_NUM + 1);

        for(int i = 0; i < N; ++i){
            int dpPrev = (i == 0 ? 0 : dp[i - 1]);
            int importanceValue = k;
            fill(count.begin(), count.end(), 0);

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