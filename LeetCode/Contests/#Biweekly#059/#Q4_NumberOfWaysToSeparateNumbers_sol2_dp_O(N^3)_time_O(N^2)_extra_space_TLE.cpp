class Solution {
public:
    int numberOfCombinations(string num) {
        const int N = num.length();
        const int MODULO = 1e9 + 7;
        
        if(num[0] == '0'){
            return 0;
        }
        
        // dp[i][j]: number of possible lists of integers from num[0 .. j] with the last integer num[i .. j]
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        fill(dp[0].begin(), dp[0].end(), 1);
        
        for(int i = 1; i < N; ++i){
            if(num[i] == '0'){
                continue;
            }
            for(int j = i; j < N; ++j){
                int len = j - i + 1;
                for(int k = i - 1; k >= max(0, i - len + 1); --k){
                    dp[i][j] += dp[k][i - 1];
                    dp[i][j] %= MODULO;
                }
                if(i - len >= 0 && num.compare(i - len, len, num, i, len) <= 0){
                    dp[i][j] += dp[i - len][i - 1];
                    dp[i][j] %= MODULO;
                }
            }
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            answer += dp[i][N - 1];
            answer %= MODULO;
        }
        
        return answer;
    }
};