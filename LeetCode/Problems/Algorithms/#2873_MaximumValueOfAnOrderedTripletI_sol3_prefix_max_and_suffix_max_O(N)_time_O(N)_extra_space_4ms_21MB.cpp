class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int N = nums.size();

        vector<int> prefMax(N);
        prefMax[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        vector<int> suffMax(N);
        suffMax[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffMax[i] = max(nums[i], suffMax[i + 1]);
        }

        long long res = 0;
        for(int j = 1; j + 1 < N; ++j){
            long long prod = (long long)(prefMax[j - 1] - nums[j]) * (long long)suffMax[j + 1];
            res = max(res, prod);
        }

        return res;
    }
};