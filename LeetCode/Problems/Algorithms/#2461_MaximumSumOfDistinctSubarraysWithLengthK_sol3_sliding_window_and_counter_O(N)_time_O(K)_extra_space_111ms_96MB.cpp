class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();

        long long maxSum = 0;
        long long sum = 0;
        unordered_map<int, int> freq;

        for(int i = 0; i < N; ++i){
            sum += nums[i];
            freq[nums[i]] += 1;
            if(i >= k){
                sum -= nums[i - k];
                freq[nums[i - k]] -= 1;
                if(freq[nums[i - k]] == 0){
                    freq.erase(nums[i - k]);
                }
            }

            if((int)freq.size() == k){
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};