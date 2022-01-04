class Solution {
public:
    int longestDecomposition(string text) {
        const int N = text.length();
        const long long BASE = 131;
        const long long MODULO = 1e9 + 7;
        
        text = "$" + text;
        
        vector<long long> h(N + 1);
        vector<long long> p(N + 1);
        p[0] = 1;
        for(int i = 1; i <= N; ++i){
            h[i] = (h[i - 1] * BASE + text[i] - 'a' + 1) % MODULO;
            p[i] = (p[i - 1] * BASE) % MODULO;
        }
        
        // dp[i]: largest k when the last included substring is subtext[j .. i]
        vector<int> dp(N + 1);
        for(int i = 1; i <= N; ++i){
            for(int j = i; j >= 1; --j){
                if(j - 1 == 0 || dp[j - 1] >= 1){
                    int len = i - j + 1;
                    int lHash = (h[i] - ((h[j - 1] * p[len]) % MODULO) + MODULO) % MODULO;
                    int rHash = (h[N - j + 1] - ((h[N - i] * p[len]) % MODULO) + MODULO) % MODULO;
                    if(lHash == rHash){
                        dp[i] = max(dp[i], dp[j - 1] + 1);
                        break;
                    }
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};