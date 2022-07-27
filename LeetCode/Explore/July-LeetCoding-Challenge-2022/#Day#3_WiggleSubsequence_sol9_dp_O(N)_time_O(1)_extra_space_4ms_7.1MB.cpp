class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int N = nums.size();
        
        // At step i:
        //    maxDec: length of the longest wiggle subsequence ending in the range [0 .. i]
        //            such that the last two elements of subsequence are decreasing (nums[j] > nums[i])
        //    maxInc: length of the longest wiggle subsequence ending in the range [0 .. i]
        //            such that the last two elements of subsequence are increasing (nums[j] < nums[i])
        int maxDec = 1;
        int maxInc = 1;
        for(int i = 1; i < N; ++i){
            if(nums[i - 1] < nums[i]){
                maxInc = maxDec + 1;
            }else if(nums[i - 1] > nums[i]){
                maxDec = maxInc + 1;
            }
        }
        
        return max(maxDec, maxInc);
    }
};