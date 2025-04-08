class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;
        long long iMax = nums[0];
        long long ijMaxDiff = 0;

        for(int j = 1; j + 1 < N; ++j){
            ijMaxDiff = max(ijMaxDiff, iMax - nums[j]);
            res = max(res, ijMaxDiff * (long long)nums[j + 1]);
            iMax = max(iMax, (long long)nums[j]);
        }

        return res;
    }
};