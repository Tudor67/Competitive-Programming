class Solution {
public:
    int numDecodings(string s) {
        const int MODULO = 1e9 + 7;
        const int N = s.length();
                
        unordered_map<string, int> groupCount;
        for(int i = 1; i <= 26; ++i){
            groupCount[to_string(i)] = 1;
        }
        
        groupCount["**"] = 9 + 6;
        groupCount["1*"] = 9;
        groupCount["2*"] = 6;
        groupCount["*"] = 9;
        for(int i = 0; i <= 9; ++i){
            if(i <= 6){
                groupCount["*" + to_string(i)] = 2;
            }else{
                groupCount["*" + to_string(i)] = 1;
            }
        }
        
        // dp[i]: number of ways to decode s[0 .. i]
        vector<int> dp(N, 0);
        dp[0] = groupCount[s.substr(0, 1)];
        if(N >= 2){
            dp[1] = dp[0] * groupCount[s.substr(1, 1)] + groupCount[s.substr(0, 2)];
        }
        for(int i = 2; i < N; ++i){
            string d = s.substr(i, 1);
            if(groupCount.count(d)){
                dp[i] += (dp[i - 1] * 1LL * groupCount[d]) % MODULO;
                dp[i] %= MODULO;
            }
            string dd = s.substr(i - 1, 2);
            if(groupCount.count(dd)){
                dp[i] += (dp[i - 2] * 1LL * groupCount[dd]) % MODULO;
                dp[i] %= MODULO;
            }
        }
        
        return dp[N - 1];
    }
};