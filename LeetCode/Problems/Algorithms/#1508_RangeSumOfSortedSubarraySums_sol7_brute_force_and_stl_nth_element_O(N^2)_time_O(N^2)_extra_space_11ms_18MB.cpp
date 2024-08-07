class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;

        vector<int> sums;
        sums.reserve(N * (N + 1) / 2);
        
        for(int i = 0; i < N; ++i){
            int sum = 0;
            for(int j = i; j < N; ++j){
                sum += nums[j];
                sums.push_back(sum);
            }
        }

        nth_element(sums.begin(), sums.begin() + left - 1, sums.end());
        nth_element(sums.begin() + left, sums.begin() + right - 1, sums.end());

        int rangeSum = 0;
        for(int i = left - 1; i <= right - 1; ++i){
            rangeSum += sums[i];
            rangeSum %= MODULO;
        }

        return rangeSum;
    }
};