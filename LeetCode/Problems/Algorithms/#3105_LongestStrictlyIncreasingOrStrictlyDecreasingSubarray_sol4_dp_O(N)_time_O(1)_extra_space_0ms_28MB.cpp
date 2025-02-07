class Solution {
private:
    int computeMaxIncSubarrayLen(vector<int>& nums, int startIndex, int endIndex, int step){
        int maxIncLen = 1;
        int incLen = 1;
        for(int i = startIndex + step; i != endIndex; i += step){
            if(nums[i - step] < nums[i]){
                incLen += 1;
                maxIncLen = max(maxIncLen, incLen);
            }else{
                incLen = 1;
            }
        }
        return maxIncLen;
    }

public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const int N = nums.size();
        return max(computeMaxIncSubarrayLen(nums, 0, N, 1),
                   computeMaxIncSubarrayLen(nums, N - 1, -1, -1));
    }
};