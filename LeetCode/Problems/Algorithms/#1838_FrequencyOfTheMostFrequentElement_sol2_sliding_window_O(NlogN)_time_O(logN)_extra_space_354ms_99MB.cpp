class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        long long maxLen = 0;
        long long currentSum = 0;
        for(int i = 0; i < N; ++i){
            maxLen += 1;
            currentSum += nums[i];
            long long targetSum = maxLen * nums[i];
            long long need = targetSum - currentSum;
            if(need > k){
                maxLen -= 1;
                currentSum -= nums[i - maxLen];
            }
        }
        
        return maxLen;
    }
};