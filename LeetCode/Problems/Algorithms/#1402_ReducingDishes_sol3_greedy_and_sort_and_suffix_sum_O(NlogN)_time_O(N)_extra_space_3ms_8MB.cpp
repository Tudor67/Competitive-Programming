class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        const int N = satisfaction.size();

        vector<int> sortedSatisfaction = satisfaction;
        sort(sortedSatisfaction.begin(), sortedSatisfaction.end());

        int res = 0;
        int weightedSum = 0;
        int suffSum = 0;
        for(int i = N - 1; i >= 0; --i){
            suffSum += sortedSatisfaction[i];
            weightedSum += suffSum;
            res = max(res, weightedSum);
        }

        return res;
    }
};