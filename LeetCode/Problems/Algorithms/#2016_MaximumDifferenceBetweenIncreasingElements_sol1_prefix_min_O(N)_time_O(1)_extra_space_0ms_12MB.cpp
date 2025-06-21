class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;
        int prefMin = nums[0];
        for(int num: nums){
            if(prefMin < num){
                maxDiff = max(maxDiff, num - prefMin);
            }
            prefMin = min(prefMin, num);
        }
        return maxDiff;
    }
};