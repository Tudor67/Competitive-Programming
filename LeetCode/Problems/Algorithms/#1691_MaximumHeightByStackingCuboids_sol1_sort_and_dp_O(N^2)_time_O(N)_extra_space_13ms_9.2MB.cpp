class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        const int N = cuboids.size();
        
        for(int i = 0; i < N; ++i){
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        
        sort(cuboids.begin(), cuboids.end());
        
        // dp[i]: max height when cuboids[i] is on top of the stack with increasing dimensions
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            dp[i] = cuboids[i][2];
            for(int j = 0; j < i; ++j){
                if(cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]){
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};