class Solution {
public:
    int numberOfCombinations(string num) {        
        if(num[0] == '0'){
            return 0;
        }
        
        const int N = num.length();
        const int MODULO = 1e9 + 7;
        
        // lcp[i][j]: length of the longest common prefix of num[i .. ] and num[j ..]
        int lcp[N][N];
        for(int i = N - 1; i >= 0; --i){
            for(int j = N - 1; j >= 0; --j){
                if(num[i] == num[j]){
                    if(i + 1 < N && j + 1 < N){
                        lcp[i][j] = 1 + lcp[i + 1][j + 1];
                    }else{
                        lcp[i][j] = 1;
                    }
                }else{
                    lcp[i][j] = 0;
                }
            }
        }
        
        // dp[i][j]: number of possible lists of integers from num[0 .. j] with the last integer num[i .. j]
        int dp[N][N];
        for(int i = 0; i < N; ++i){
            for(int j = i; j < N; ++j){
                dp[i][j] = 0;
            }
        }
        
        fill(dp[0], dp[0] + N, 1);
        
        for(int i = 1; i < N; ++i){
            if(num[i] == '0'){
                continue;
            }
            // sum = dp[k + 1][i - 1] + dp[k + 2][i - 1] + ... + dp[i - 1][i - 1]
            int sum = 0;
            int k = i - 1;
            for(int j = i; j < N; ++j){
                if(0 <= k + 1 && k + 1 <= i - 1){
                    sum += dp[k + 1][i - 1];
                    sum %= MODULO;
                }
                dp[i][j] += sum;
                dp[i][j] %= MODULO;
                int len = j - i + 1;
                if(k >= 0 && i - k == len){
                    if(lcp[k][i] >= len || num[k + lcp[k][i]] < num[i + lcp[k][i]]){
                        dp[i][j] += dp[k][i - 1];
                        dp[i][j] %= MODULO;
                    }
                }
                k -= 1;
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