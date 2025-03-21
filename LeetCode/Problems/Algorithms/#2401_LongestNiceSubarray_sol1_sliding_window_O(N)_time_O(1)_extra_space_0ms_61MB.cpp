class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        const int N = nums.size();

        int maxValidLen = 0;

        int l = 0;
        int wMask = 0;
        for(int r = 0; r < N; ++r){
            while(l < r && (wMask & nums[r]) != 0){
                wMask ^= nums[l];
                l += 1;
            }
            wMask |= nums[r];
            maxValidLen = max(maxValidLen, r - l + 1);
        }

        return maxValidLen;
    }
};