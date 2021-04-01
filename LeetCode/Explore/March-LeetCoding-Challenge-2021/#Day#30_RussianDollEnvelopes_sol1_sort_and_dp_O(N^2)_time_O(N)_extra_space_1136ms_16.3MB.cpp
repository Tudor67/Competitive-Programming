class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        
        const int N = envelopes.size();
        vector<int> dp(N, 1);
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]){
                    dp[i] = max(1 + dp[j], dp[i]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};