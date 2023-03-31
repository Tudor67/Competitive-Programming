class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        const int N = satisfaction.size();

        vector<int> sortedSatisfaction = satisfaction;
        sort(sortedSatisfaction.begin(), sortedSatisfaction.end());

        vector<int> suffSum(N);
        suffSum[N - 1] = sortedSatisfaction[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffSum[i] = sortedSatisfaction[i] + suffSum[i + 1];
        }

        int weightedSum = 0;
        int coef = 1;
        for(int i = 0; i < N; ++i){
            weightedSum += coef * sortedSatisfaction[i];
            coef += 1;
        }

        int res = 0;
        for(int i = 0; i < N; ++i){
            res = max(res, weightedSum);
            weightedSum -= suffSum[i];
        }

        return res;
    }
};