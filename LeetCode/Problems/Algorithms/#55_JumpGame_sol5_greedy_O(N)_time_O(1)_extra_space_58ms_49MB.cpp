class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();

        int maxPos = 0;
        for(int i = 0; i < N; ++i){
            if(maxPos < i){
                return false;
            }
            maxPos = max(maxPos, i + nums[i]);
        }

        return true;
    }
};