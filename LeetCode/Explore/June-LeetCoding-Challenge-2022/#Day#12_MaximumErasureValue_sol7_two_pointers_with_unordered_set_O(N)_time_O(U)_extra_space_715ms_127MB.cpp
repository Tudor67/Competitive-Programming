class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_set<int> vis;
        int maxSum = 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        while(j < N){
            if(vis.count(nums[j])){
                sum -= nums[i];
                vis.erase(nums[i]);
                i += 1;
            }else{
                sum += nums[j];
                vis.insert(nums[j]);
                maxSum = max(maxSum, sum);
                j += 1;
            }
        }
        
        return maxSum;
    }
};