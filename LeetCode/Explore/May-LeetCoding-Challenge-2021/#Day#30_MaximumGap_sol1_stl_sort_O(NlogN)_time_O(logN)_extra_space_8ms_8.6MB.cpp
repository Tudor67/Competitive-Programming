class Solution {    
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int maxGap = 0;
        for(int i = 1; i < (int)nums.size(); ++i){
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }
        
        return maxGap;
    }
};