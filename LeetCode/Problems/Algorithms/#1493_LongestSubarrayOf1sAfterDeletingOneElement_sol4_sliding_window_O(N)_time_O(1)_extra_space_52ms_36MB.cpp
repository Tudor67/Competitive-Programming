class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        int l = 0;
        int zeros = 0;
        for(int r = 0; r < N; ++r){
            zeros += (int)(nums[r] == 0);
            while(zeros >= 2){
                zeros -= (int)(nums[l] == 0);
                l += 1;
            }
            res = max(res, r - l);
        }

        return res;
    }
};