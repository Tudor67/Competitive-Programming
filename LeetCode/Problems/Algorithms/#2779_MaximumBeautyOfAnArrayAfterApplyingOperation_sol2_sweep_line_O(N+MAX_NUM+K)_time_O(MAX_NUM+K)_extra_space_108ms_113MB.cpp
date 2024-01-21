class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> delta(MAX_NUM + 2 * k + 2);
        for(int num: nums){
            delta[k + num - k] += 1;
            delta[k + num + k + 1] -= 1;
        }

        int res = 0;
        int activeRanges = 0;
        for(int i = 0; i < (int)delta.size(); ++i){
            activeRanges += delta[i];
            res = max(res, activeRanges);
        }

        return res;
    }
};