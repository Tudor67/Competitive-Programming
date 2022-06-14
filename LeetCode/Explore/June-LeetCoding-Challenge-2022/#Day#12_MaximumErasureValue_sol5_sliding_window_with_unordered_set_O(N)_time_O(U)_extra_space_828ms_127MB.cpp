class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_set<int> vis;
        int maxSum = 0; // max sum of a subarray containing unique elements
        int sum = 0;    // max sum of subarray nums[i .. j] ending at index j and containing unique elements
        int i = 0;
        for(int j = 0; j < N; ++j){
            while(vis.count(nums[j])){
                sum -= nums[i];
                vis.erase(nums[i]);
                i += 1;
            }
            sum += nums[j];
            vis.insert(nums[j]);
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};