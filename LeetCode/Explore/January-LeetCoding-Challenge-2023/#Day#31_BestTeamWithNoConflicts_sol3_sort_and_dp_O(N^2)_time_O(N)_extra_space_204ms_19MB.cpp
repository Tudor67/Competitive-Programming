class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int N = scores.size();

        vector<pair<int, int>> sortedAgesScores(N);
        for(int i = 0; i < N; ++i){
            sortedAgesScores[i] = {ages[i], scores[i]};
        }

        sort(sortedAgesScores.begin(), sortedAgesScores.end());

        // dp[i]: highest overall score of sorted players[0 .. i]
        //        when sorted player[i] is included in the best team
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            dp[i] = sortedAgesScores[i].second;
            for(int j = 0; j < i; ++j){
                if(sortedAgesScores[j].second <= sortedAgesScores[i].second){
                    dp[i] = max(dp[i], dp[j] + sortedAgesScores[i].second);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};