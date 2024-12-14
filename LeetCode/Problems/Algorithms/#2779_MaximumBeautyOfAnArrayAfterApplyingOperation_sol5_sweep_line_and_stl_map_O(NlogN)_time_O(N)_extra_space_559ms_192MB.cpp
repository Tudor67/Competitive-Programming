class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        const int N = nums.size();

        map<int, int> delta;
        for(int num: nums){
            delta[num - k] += 1;
            delta[num + k + 1] -= 1;
        }

        int maxBeauty = 0;
        int activeSegments = 0;
        for(const auto& [_, currDelta]: delta){
            activeSegments += currDelta;
            maxBeauty = max(maxBeauty, activeSegments);
        }

        return maxBeauty;
    }
};