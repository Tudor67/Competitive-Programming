class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MODULO = 1'000'000'007;

        vector<int> pows;
        for(int i = 1; i <= n; ++i){
            int p = pow(i, x);
            if(p <= n){
                pows.push_back(p);
            }else{
                break;
            }
        }
        
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int p: pows){
            for(int sum = n; sum >= p; --sum){
                dp[sum] += dp[sum - p];
                dp[sum] %= MODULO;
            }
        }

        return dp[n];
    }
};