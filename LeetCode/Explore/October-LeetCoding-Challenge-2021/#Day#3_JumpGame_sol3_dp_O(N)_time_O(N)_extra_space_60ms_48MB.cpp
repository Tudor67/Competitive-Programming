class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        
        // isPossible[i]: true, if is possible to reach the last index when you start at pos i
        //                false, otherwise
        vector<bool> isPossible(N, false);
        isPossible[N - 1] = true;
        int closestPosOfTrue = N - 1;
        for(int i = N - 2; i >= 0; --i){
            if(i + nums[i] >= closestPosOfTrue){
                isPossible[i] = true;
                closestPosOfTrue = i;
            }
        }
        
        return isPossible[0];
    }
};