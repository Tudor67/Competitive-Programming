class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        // dp[i]: size of the largest valid subset from nums[0 .. i] which includes nums[i]
        vector<int> dp(N);
        vector<int> prev(N);
        for(int i = 0; i < N; ++i){
            dp[i] = 1;
            prev[i] = i;
            for(int j = 0; j < i; ++j){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        
        vector<int> numsSubset;
        int pos = max_element(dp.begin(), dp.end()) - dp.begin();
        while(pos != prev[pos]){
            numsSubset.push_back(nums[pos]);
            pos = prev[pos];
        }
        numsSubset.push_back(nums[pos]);
        
        return numsSubset;
    }
};