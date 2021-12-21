class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // numbers less than or equal to n <=> numbers less than n + 1
        n += 1;
        
        const string N_STR = to_string(n);
        const int N_LEN = N_STR.length();
        const int DIGITS_SIZE = digits.size();
        
        // dp[i]: how many numbers of length i less than n can be generated with `digits`
        vector<int> dp(N_LEN + 1);
        dp[0] = 1;
        for(int i = 1; i <= N_LEN - 1; ++i){
            dp[i] = dp[i - 1] * DIGITS_SIZE;
        }
        
        bool isPrefixWithValidDigits = true;
        for(int i = 0; isPrefixWithValidDigits && i <= N_LEN - 1; ++i){
            int lessThanCurrentDigit = lower_bound(digits.begin(), digits.end(), string(1, N_STR[i])) - digits.begin();
            if(lessThanCurrentDigit >= 1){
                dp[N_LEN] += lessThanCurrentDigit * dp[N_LEN - 1 - i];
            }
            if(!binary_search(digits.begin(), digits.end(), string(1, N_STR[i]))){
                isPrefixWithValidDigits = false;
            }
        }
        
        return accumulate(dp.begin() + 1, dp.end(), 0);
    }
};