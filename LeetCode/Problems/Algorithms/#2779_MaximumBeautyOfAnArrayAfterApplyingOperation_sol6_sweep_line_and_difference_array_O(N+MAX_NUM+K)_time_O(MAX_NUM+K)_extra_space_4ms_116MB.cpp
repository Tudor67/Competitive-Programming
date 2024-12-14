class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> delta(MAX_NUM + 2 * k + 2);
        for(int num: nums){
            delta[num] += 1;
            delta[num + 2 * k + 1] -= 1;
        }

        int maxBeauty = 0;
        int activeSegments = 0;
        for(int currDelta: delta){
            activeSegments += currDelta;
            maxBeauty = max(maxBeauty, activeSegments);
        }

        return maxBeauty;
    }
};