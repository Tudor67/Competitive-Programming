class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        const int N = satisfaction.size();

        vector<int> sortedSatisfaction = satisfaction;
        sort(sortedSatisfaction.begin(), sortedSatisfaction.end());

        int res = 0;
        for(int i = 0; i < N; ++i){
            int sum = 0;
            int coef = 1;
            for(int j = i; j < N; ++j){
                sum += coef * sortedSatisfaction[j];
                coef += 1;
            }
            res = max(res, sum);
        }

        return res;
    }
};