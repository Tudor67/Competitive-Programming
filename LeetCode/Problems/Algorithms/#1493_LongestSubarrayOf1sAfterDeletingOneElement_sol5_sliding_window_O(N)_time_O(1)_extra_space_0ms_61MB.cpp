class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();

        int maxLen = 0;
        int zeros = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            zeros += (int)(nums[r] == 0);
            while(zeros > 1){
                zeros -= (int)(nums[l] == 0);
                l += 1;
            }
            maxLen = max(maxLen, r - l);
        }

        return maxLen;
    }
};