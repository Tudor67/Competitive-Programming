class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;
        long long maxPref = nums[0];
        long long maxPrefDiff = 0;
        for(int j = 1; j + 1 < N; ++j){
            maxPrefDiff = max(maxPrefDiff, maxPref - nums[j]);
            res = max(res, maxPrefDiff * nums[j + 1]);
            maxPref = max(maxPref, (long long)nums[j]);
        }

        return res;
    }
};