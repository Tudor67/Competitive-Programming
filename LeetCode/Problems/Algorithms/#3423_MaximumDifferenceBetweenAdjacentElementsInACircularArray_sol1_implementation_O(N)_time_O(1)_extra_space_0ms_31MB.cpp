class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        const int N = nums.size();

        int maxAdjDist = abs(nums.front() - nums.back());
        for(int i = 0; i + 1 < N; ++i){
            maxAdjDist = max(maxAdjDist, abs(nums[i] - nums[i + 1]));
        }

        return maxAdjDist;
    }
};