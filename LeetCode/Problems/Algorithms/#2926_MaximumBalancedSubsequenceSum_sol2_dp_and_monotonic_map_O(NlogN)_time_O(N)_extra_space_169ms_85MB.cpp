class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        const int N = nums.size();

        long long res = *max_element(nums.begin(), nums.end());
        map<int, long long> maxSum;

        for(int i = 0; i < N; ++i){
            if(nums[i] < 0){
                continue;
            }

            int diff = nums[i] - i;

            map<int, long long>::iterator it = maxSum.upper_bound(diff);
            if(maxSum.empty() || it == maxSum.begin()){
                maxSum[diff] = nums[i];
            }else{
                maxSum[diff] = max((long long)0, prev(it)->second) + nums[i];
            }
            
            while(it != maxSum.begin() && it != maxSum.end() && prev(it)->second >= it->second){
                it = maxSum.erase(it);
            }

            res = max(res, maxSum[diff]);
        }

        return res;
    }
};