class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();
        
        long long res = 0;
        long long sum = 0;
        unordered_map<int, int> count;
        for(int i = 0; i < N; ++i){
            sum += nums[i];
            count[nums[i]] += 1;
            if(i >= k){
                sum -= nums[i - k];
                count[nums[i - k]] -= 1;
                if(count[nums[i - k]] == 0){
                    count.erase(nums[i - k]);
                }
            }
            if((int)count.size() == k){
                res = max(res, sum);
            }
        }
        
        return res;
    }
};