class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;

        vector<int> sortedSums;
        sortedSums.reserve(N * (N + 1) / 2);
        
        for(int i = 0; i < N; ++i){
            int sum = 0;
            for(int j = i; j < N; ++j){
                sum += nums[j];
                sortedSums.push_back(sum);
            }
        }

        sort(sortedSums.begin(), sortedSums.end());

        int rangeSum = 0;
        for(int i = left - 1; i <= right - 1; ++i){
            rangeSum += sortedSums[i];
            rangeSum %= MODULO;
        }

        return rangeSum;
    }
};