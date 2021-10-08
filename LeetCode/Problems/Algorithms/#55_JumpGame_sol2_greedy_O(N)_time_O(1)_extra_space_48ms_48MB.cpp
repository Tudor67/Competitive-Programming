class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        int maxPos = 0;
        int pos = 0;
        while(pos <= maxPos && maxPos < N - 1){
            maxPos = max(maxPos, pos + nums[pos]);
            pos += 1;
        }
        return (maxPos >= N - 1);
    }
};