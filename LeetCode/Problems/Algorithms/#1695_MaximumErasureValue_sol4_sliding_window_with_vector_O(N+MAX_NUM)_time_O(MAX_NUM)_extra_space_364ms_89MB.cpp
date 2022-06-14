class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        vector<bool> vis(MAX_NUM + 1, false);
        int maxSum = 0; // max sum of a subarray containing unique elements
        int sum = 0;    // max sum of subarray nums[i .. j] ending at index j and containing unique elements
        int i = 0;
        for(int j = 0; j < N; ++j){
            while(vis[nums[j]]){
                sum -= nums[i];
                vis[nums[i]] = false;
                i += 1;
            }
            sum += nums[j];
            vis[nums[j]] = true;
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};