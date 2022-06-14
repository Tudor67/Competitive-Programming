class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        vector<bool> vis(MAX_NUM + 1, false);
        int maxSum = 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        while(j < N){
            if(vis[nums[j]]){
                sum -= nums[i];
                vis[nums[i]] = false;
                i += 1;
            }else{
                sum += nums[j];
                vis[nums[j]] = true;
                maxSum = max(maxSum, sum);
                j += 1;
            }
        }
        
        return maxSum;
    }
};