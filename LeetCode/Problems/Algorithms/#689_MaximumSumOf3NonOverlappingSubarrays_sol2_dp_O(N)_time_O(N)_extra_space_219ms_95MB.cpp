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

        // dpSum[c][i]: max sum of c non-overlapping subarrays of length k from nums[i .. N - 1]
        // dpSumIndices[c][i]: lexicographically smallest indices corresponding to dpSum[c][i]
        vector<vector<int>> dpSum(4, vector<int>(N + 1));
        vector<vector<vector<int>>> dpSumIndices(4, vector<vector<int>>(N + 1));
        for(int c = 1; c <= 3; ++c){
            for(int i = N - k; i >= 0; --i){
                int sum1 = computeRangeSum(i, i + k - 1) + dpSum[c - 1][i + k];
                vector<int> sum1Indices = dpSumIndices[c - 1][i + k];
                sum1Indices.insert(sum1Indices.begin(), i);

                int sum2 = dpSum[c][i + 1];
                vector<int> sum2Indices = dpSumIndices[c][i + 1];

                if(sum1 >= sum2){
                    dpSum[c][i] = sum1;
                    dpSumIndices[c][i] = sum1Indices;
                }else{
                    dpSum[c][i] = sum2;
                    dpSumIndices[c][i] = sum2Indices;
                }
            }
        }

        return dpSumIndices[3][0];
    }
};