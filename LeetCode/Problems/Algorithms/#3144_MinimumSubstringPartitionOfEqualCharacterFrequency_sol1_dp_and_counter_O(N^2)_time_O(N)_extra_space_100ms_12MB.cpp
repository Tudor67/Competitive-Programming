class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        const int N = s.length();
        const int A = 26;
        const char FIRST_ELEM = 'a';

        // dp[i]: min partitions for s[0 .. i]
        vector<int> dp(N);
        vector<int> freq(A);
        vector<int> ff(N + 1);

        for(int i = 0; i < N; ++i){
            dp[i] = i + 1;

            int distinctFreqs = 0;
            for(int j = i; j >= 0; --j){
                int cIdx = s[j] - FIRST_ELEM;

                ff[freq[cIdx]] -= 1;
                distinctFreqs -= (int)(ff[freq[cIdx]] == 0);
                freq[cIdx] += 1;
                ff[freq[cIdx]] += 1;
                distinctFreqs += (int)(ff[freq[cIdx]] == 1);

                if(distinctFreqs == 1){
                    if(j == 0){
                        dp[i] = 1;
                    }else{
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }

            for(char c = FIRST_ELEM; c < FIRST_ELEM + A; ++c){
                ff[freq[c - FIRST_ELEM]] = 0;
                freq[c - FIRST_ELEM] = 0;
            }
        }

        return dp[N - 1];
    }
};