class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const int N = s.length();

        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        int maxWordLen = 0;
        for(const string& WORD: dictionary){
            maxWordLen = max(maxWordLen, (int)WORD.length());
        }

        // dp[i]: min cost for s[i ..]
        vector<int> dp(N + 1);
        for(int i = N - 1; i >= 0; --i){
            dp[i] = 1 + dp[i + 1];
            string w;
            for(int j = i; j < N && (int)w.length() < maxWordLen; ++j){
                w += s[j];
                if(dictSet.count(w)){
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};