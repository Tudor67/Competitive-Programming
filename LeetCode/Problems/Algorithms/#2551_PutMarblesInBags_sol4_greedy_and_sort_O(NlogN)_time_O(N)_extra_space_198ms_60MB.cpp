class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        const int N = weights.size();

        vector<int> splitCosts(N - 1);
        for(int i = 0; i < N - 1; ++i){
            splitCosts[i] = weights[i] + weights[i + 1];
        }

        sort(splitCosts.begin(), splitCosts.end());
        
        int splitOperations = k - 1;
        long long minScore = weights[0] + weights[N - 1] + accumulate(splitCosts.begin(), splitCosts.begin() + splitOperations, 0LL);
        long long maxScore = weights[0] + weights[N - 1] + accumulate(splitCosts.end() - splitOperations, splitCosts.end(), 0LL);

        return maxScore - minScore;
    }
};