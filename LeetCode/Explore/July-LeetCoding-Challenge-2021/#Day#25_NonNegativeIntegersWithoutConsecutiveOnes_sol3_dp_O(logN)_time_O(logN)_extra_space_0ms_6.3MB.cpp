class Solution {
public:
    int findIntegers(int n) {
        const int NON_ZERO_MSB = floor(log2(n));
        
        // dp[i]: count of binary numbers with i bits
        //        which don't contain consecutive 1's
        vector<int> dp(NON_ZERO_MSB + 2);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i <= NON_ZERO_MSB + 1; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        int answer = 0;
        bool containsConsecutiveOnes = false;
        for(int bit = NON_ZERO_MSB; !containsConsecutiveOnes && bit >= 0; --bit){
            if((n >> bit) & 1){
                answer += dp[bit];
            }
            if(((n >> (bit + 1)) & 1) && ((n >> bit) & 1)){
                containsConsecutiveOnes = true;
            }
        }
        
        if(!containsConsecutiveOnes){
            answer += 1;
        }
        
        return answer;
    }
};