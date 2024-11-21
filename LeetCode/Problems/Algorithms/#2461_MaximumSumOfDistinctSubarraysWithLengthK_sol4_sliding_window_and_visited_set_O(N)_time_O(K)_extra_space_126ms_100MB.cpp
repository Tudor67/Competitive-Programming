class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();

        long long maxSum = 0;
        long long sum = 0;
        unordered_set<int> vis;

        int l = 0;
        for(int r = 0; r < N; ++r){
            sum += nums[r];
            while(r - l + 1 > k || vis.count(nums[r])){
                sum -= nums[l];
                vis.erase(nums[l]);
                l += 1;
            }

            vis.insert(nums[r]);

            if(r - l + 1 == k){
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};