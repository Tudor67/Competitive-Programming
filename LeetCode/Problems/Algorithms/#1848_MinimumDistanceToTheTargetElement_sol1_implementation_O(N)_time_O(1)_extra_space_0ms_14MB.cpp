class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        const int N = nums.size();

        int minDist = N;
        for(int i = 0; i < N; ++i){
            if(nums[i] == target){
                minDist = min(minDist, abs(i - start));
            }
        }

        return minDist;
    }
};