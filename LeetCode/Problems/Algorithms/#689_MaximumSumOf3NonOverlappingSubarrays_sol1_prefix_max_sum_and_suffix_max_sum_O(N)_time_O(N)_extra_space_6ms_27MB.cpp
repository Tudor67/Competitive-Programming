class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        auto computeRangeSum = [&](int l, int r){
            if(l > r) return 0;
            if(l == 0) return prefSum[r];
            return prefSum[r] - prefSum[l - 1];
        };

        vector<int> suffMaxSum(N + 1);
        vector<int> suffMaxSumIndex(N + 1);
        for(int i = N - k; i >= 0; --i){
            suffMaxSum[i] = computeRangeSum(i, i + k - 1);
            suffMaxSumIndex[i] = i;
            if(suffMaxSum[i] < suffMaxSum[i + 1]){
                suffMaxSum[i] = suffMaxSum[i + 1];
                suffMaxSumIndex[i] = suffMaxSumIndex[i + 1];
            }
        }

        int prefMaxSum = computeRangeSum(0, k - 1);
        int prefMaxSumIndex = 0;

        int resSum = 0;
        vector<int> resSumIndices;
        for(int i = k; i + k - 1 < N - k; ++i){
            int midSum = computeRangeSum(i, i + k - 1);
            int sum = prefMaxSum + midSum + suffMaxSum[i + k];
            if(resSum < sum){
                resSum = sum;
                resSumIndices = {prefMaxSumIndex, i, suffMaxSumIndex[i + k]};
            }

            int s = computeRangeSum(i - k + 1, i);
            if(prefMaxSum < s){
                prefMaxSum = s;
                prefMaxSumIndex = i - k + 1;
            }
        }

        return resSumIndices;
    }
};