class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const int N = nums.size();

        int maxLen = 1;
        int incLen = 1;
        int decLen = 1;
        for(int i = 1; i < N; ++i){
            if(nums[i - 1] < nums[i]){
                incLen += 1;
                decLen = 1;
                maxLen = max(maxLen, incLen);
            }else if(nums[i - 1] > nums[i]){
                decLen += 1;
                incLen = 1;
                maxLen = max(maxLen, decLen);
            }else{
                incLen = 1;
                decLen = 1;
            }
        }

        return maxLen;
    }
};