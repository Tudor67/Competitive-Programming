class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        const int N = nums.size();

        map<int, int> delta;
        for(int num: nums){
            delta[num - k] += 1;
            delta[num + k + 1] -= 1;
        }

        int res = 0;
        int activeRanges = 0;
        for(const pair<const int, int>& P: delta){
            activeRanges += P.second;
            res = max(res, activeRanges);
        }

        return res;
    }
};