class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        int closestPosOfTrue = N - 1;
        for(int i = N - 2; i >= 0; --i){
            if(i + nums[i] >= closestPosOfTrue){
                closestPosOfTrue = i;
            }
        }
        return (closestPosOfTrue == 0);
    }
};