class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        const int N = values.size();

        int maxScore = 0;
        int maxPref = values[0];
        for(int i = 1; i < N; ++i){
            maxScore = max(maxScore, maxPref + values[i] - i);
            maxPref = max(maxPref, values[i] + i);
        }

        return maxScore;
    }
};