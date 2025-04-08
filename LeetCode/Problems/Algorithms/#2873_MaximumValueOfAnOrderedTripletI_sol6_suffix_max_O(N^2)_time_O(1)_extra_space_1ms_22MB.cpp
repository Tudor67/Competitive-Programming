class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;
        for(int i = 0; i < N; ++i){
            int maxSuffVal = nums[N - 1];
            for(int j = N - 2; j > i; --j){
                res = max(res, (long long)(nums[i] - nums[j]) * (long long)maxSuffVal);
                maxSuffVal = max(maxSuffVal, nums[j]);
            }
        }

        return res;
    }
};