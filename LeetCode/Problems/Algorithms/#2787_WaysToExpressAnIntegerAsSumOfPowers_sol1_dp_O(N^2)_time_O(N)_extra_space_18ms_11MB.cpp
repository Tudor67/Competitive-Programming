class Solution {
private:
    int pow(int a, int n){
        int p = 1;
        for(int i = 1; i <= n; ++i){
            p *= a;
        }
        return p;
    }

public:
    int numberOfWays(int n, int x) {
        vector<int> pows;
        for(int i = 1; i <= n; ++i){
            int p = pow(i, x);
            if(p <= n){
                pows.push_back(p);
            }else{
                break;
            }
        }

        const int TARGET_SUM = n;
        const int MODULO = 1e9 + 7;
        vector<int> dp(TARGET_SUM + 1);
        dp[0] = 1;
        for(int p: pows){
            for(int sum = TARGET_SUM; sum >= p; --sum){
                dp[sum] += dp[sum - p];
                dp[sum] %= MODULO;
            }
        }

        return dp[TARGET_SUM];
    }
};