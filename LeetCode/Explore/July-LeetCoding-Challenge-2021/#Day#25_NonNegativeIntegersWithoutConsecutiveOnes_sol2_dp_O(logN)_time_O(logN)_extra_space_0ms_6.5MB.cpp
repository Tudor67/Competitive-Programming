class Solution {
public:
    int findIntegers(int n) {
        const int NON_ZERO_MSB = floor(log2(n));
        
        // dp[i]: count of integers in range [0 .. (2 ^ i) - 1]
        //        with at least 2 consecutive ones in their binary representation
        // dp[i] = 2 ^ i - fibonacci(i + 2)
        vector<int> fib(NON_ZERO_MSB + 3);
        fib[0] = 0;
        fib[1] = 1;
        for(int i = 2; i <= NON_ZERO_MSB + 2; ++i){
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        
        vector<int> dp(NON_ZERO_MSB + 3);
        dp[0] = 0;
        for(int i = 1; i <= NON_ZERO_MSB; ++i){
            dp[i] = (1 << i) - fib[i + 2];
        }
        
        int answer = n + 1;
        for(int bit = NON_ZERO_MSB; bit >= 0; --bit){
            if((n >> bit) & 1){
                answer -= dp[bit];
            }
            if(((n >> (bit + 1)) & 1) && ((n >> bit) & 1)){
                int suffixMask = ((1 << bit) - 1) & n;
                answer -= suffixMask;
                answer -= 1;
                break;
            }
        }
        
        return answer;
    }
};