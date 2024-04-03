class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        const int N = nums.size();

        vector<int> maxLen(target + 1, -1);
        maxLen[0] = 0;

        for(int num: nums){
            for(int sum = target; sum >= num; --sum){
                if(maxLen[sum - num] >= 0){
                    maxLen[sum] = max(maxLen[sum], maxLen[sum - num] + 1);
                }
            }
        }

        return maxLen[target];
    }
};