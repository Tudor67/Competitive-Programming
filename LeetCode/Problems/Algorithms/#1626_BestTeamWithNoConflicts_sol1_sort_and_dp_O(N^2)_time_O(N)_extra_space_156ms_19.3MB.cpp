class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int N = scores.size();
        
        vector<pair<int, int>> sortedScoreAge(N);
        for(int i = 0; i < N; ++i){
            sortedScoreAge[i] = {scores[i], ages[i]};
        }
        
        sort(sortedScoreAge.begin(), sortedScoreAge.end());
        
        // dp[i]: best team score using players from sortedScoreAge[0 .. i]
        //        with sortedScoreAge[i] player included in the team
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            dp[i] = sortedScoreAge[i].first;
            for(int j = i - 1; j >= 0; --j){
                if(sortedScoreAge[j].second <= sortedScoreAge[i].second){
                    dp[i] = max(dp[i], dp[j] + sortedScoreAge[i].first);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};