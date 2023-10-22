class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int N = nums.size();

        // dp[i]: max valid sum of a subsequence from nums[0 .. i] ending with nums[i]
        vector<int> dp(N);
        deque<int> monoDQ;
        
        for(int i = 0; i < N; ++i){
            if(!monoDQ.empty() && i - monoDQ.front() > k){
                monoDQ.pop_front();
            }

            if(monoDQ.empty()){
                dp[i] = nums[i];
            }else{
                dp[i] = nums[i] + max(0, dp[monoDQ.front()]);
            }

            while(!monoDQ.empty() && dp[monoDQ.back()] <= dp[i]){
                monoDQ.pop_back();
            }
            monoDQ.push_back(i);
        }

        return *max_element(dp.begin(), dp.end());
    }
};