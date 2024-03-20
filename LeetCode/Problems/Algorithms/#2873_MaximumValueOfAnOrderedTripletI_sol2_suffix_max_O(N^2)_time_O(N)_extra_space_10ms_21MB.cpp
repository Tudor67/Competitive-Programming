class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int N = nums.size();

        vector<int> suffMax(N);
        suffMax[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffMax[i] = max(nums[i], suffMax[i + 1]);
        }

        long long res = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j + 1 < N; ++j){
                long long prod = (long long)(nums[i] - nums[j]) * (long long)suffMax[j + 1];
                res = max(res, prod);
            }
        }

        return res;
    }
};