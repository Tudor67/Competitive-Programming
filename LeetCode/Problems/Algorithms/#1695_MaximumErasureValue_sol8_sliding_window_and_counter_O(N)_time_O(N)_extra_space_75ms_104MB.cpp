class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int N = nums.size();

        int maxSum = 0;

        unordered_map<int, int> freq;
        int sum = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            sum += nums[r];
            freq[nums[r]] += 1;
            while(freq[nums[r]] > 1){
                sum -= nums[l];
                freq[nums[l]] -= 1;
                l += 1;
            }
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};