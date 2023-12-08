class Solution {
private:
    const int MODULO = 1e9 + 7;
    
    int computeDigitSum(const string& S){
        int sum = 0;
        for(char c: S){
            sum += (c - '0');
        }
        return sum;
    }
    
    int f(const string& S, const int MAX_SUM){
        const int N = S.length();
        
        // dp[len][s]: number of integers of length len and sum of digits <= s
        //             leading zeros are allowed (i.e., 5, 05, 005, ..., 000005 are considered valid integers)
        vector<vector<int>> dp(N + 1, vector<int>(MAX_SUM + 1));
        dp[0][0] = 1;

        for(int len = 0; len + 1 <= N; ++len){
            for(int digitSum = 0; digitSum <= MAX_SUM; ++digitSum){
                for(int digit = 0; digit <= 9 && digitSum + digit <= MAX_SUM; ++digit){
                    dp[len + 1][digitSum + digit] += dp[len][digitSum];
                    dp[len + 1][digitSum + digit] %= MODULO;
                }
            }
        }
        
        for(int len = 0; len <= N; ++len){
            for(int digitSum = 1; digitSum <= MAX_SUM; ++digitSum){
                dp[len][digitSum] += dp[len][digitSum - 1];
                dp[len][digitSum] %= MODULO;
            }
        }
        
        int res = dp[N - 1][MAX_SUM];
        int prefDigitSum = 0;
        for(int i = 0; i < N; ++i){
            int minValidDigit = (i == 0 ? 1 : 0);
            int maxValidDigit = (i == N - 1 ? S[i] - '0' : S[i] - '0' - 1);
            for(int digit = minValidDigit; digit <= maxValidDigit; ++digit){
                int currPrefDigitSum = prefDigitSum + digit;
                int currLen = i + 1;
                if(currPrefDigitSum <= MAX_SUM){
                    res += dp[N - currLen][MAX_SUM - currPrefDigitSum];
                    res %= MODULO;
                }
            }
            prefDigitSum += S[i] - '0';
        }
        
        return res;
    }

public:
    int count(string num1, string num2, int minSum, int maxSum) {
        int digitSum1 = computeDigitSum(num1);
        int maxSumContrib = (f(num2, maxSum) - f(num1, maxSum) + (int)(digitSum1 <= maxSum) + MODULO) % MODULO;
        int minSumContrib = (f(num2, minSum - 1) - f(num1, minSum - 1) + (int)(digitSum1 <= minSum - 1) + MODULO) % MODULO;
        return (maxSumContrib - minSumContrib + MODULO) % MODULO;
    }
};