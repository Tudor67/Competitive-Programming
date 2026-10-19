class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        const int N = stones.size();

        vector<int> prefSum(N);
        prefSum[0] = stones[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + stones[i];
        }

        // maxDiff[i]: max difference when the current player can take
        //             stones[0 .. i], stones[0 .. i + 1], ..., or stones[0 .. N - 1]
        vector<int> maxDiff(N);
        maxDiff[N - 1] = prefSum[N - 1];
        for(int i = N - 2; i >= 1; --i){
            maxDiff[i] = max(prefSum[i] - maxDiff[i + 1], maxDiff[i + 1]);
        }

        return maxDiff[1];
    }
};