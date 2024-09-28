class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const int N = s.length();
        const int D = dictionary.size();

        int maxLen = 0;
        for(const string& WORD: dictionary){
            maxLen = max(maxLen, (int)WORD.length());
        }

        // dp[i]: min number of extra characters left over when we break up s[i .. N - 1] optimally
        vector<int> dp(N + 1);
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        for(int i = N - 1; i >= 0; --i){
            dp[i] = 1 + dp[i + 1];
            string w;
            for(int j = i; j < min(i + maxLen, N); ++j){
                w += s[j];
                if(dictSet.count(w)){
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};