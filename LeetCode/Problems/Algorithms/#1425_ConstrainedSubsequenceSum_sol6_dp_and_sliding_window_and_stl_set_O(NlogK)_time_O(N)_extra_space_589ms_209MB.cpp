class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int N = nums.size();

        // dp[i]: max valid sum of a subsequence from nums[0 .. i] ending with nums[i]
        vector<int> dp(N);
        set<pair<int, int>> w;
        
        for(int i = 0; i < N; ++i){
            if(i >= k + 1){
                w.erase({dp[i - (k + 1)], i - (k + 1)});
            }

            if(w.empty()){
                dp[i] = nums[i];
            }else{
                dp[i] = nums[i] + max(0, w.rbegin()->first);
            }

            w.insert({dp[i], i});
        }

        return *max_element(dp.begin(), dp.end());
    }
};