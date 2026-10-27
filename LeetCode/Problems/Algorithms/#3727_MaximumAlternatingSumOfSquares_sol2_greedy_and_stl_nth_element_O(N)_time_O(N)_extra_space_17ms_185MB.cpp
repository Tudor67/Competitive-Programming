class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const int N = nums.size();

        vector<int> squaredNums(N);
        for(int i = 0; i < N; ++i){
            squaredNums[i] = nums[i] * nums[i];
        }

        nth_element(squaredNums.begin(), squaredNums.begin() + N / 2, squaredNums.end());

        long long res = 0;
        for(int i = 0; i < N / 2; ++i){
            res -= squaredNums[i];
        }

        for(int i = N / 2; i < N; ++i){
            res += squaredNums[i];
        }

        return res;
    }
};