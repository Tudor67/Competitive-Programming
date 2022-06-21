class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<string> sortedWords = words;
        sort(sortedWords.begin(), sortedWords.end(),
             [](const string& LHS, const string& RHS){
                 return (LHS.length() < RHS.length());
             });
        
        // dp[word]: length of the longest chain ending with word
        unordered_map<string, int> dp;
        int maxLen = 0;
        for(string& word: sortedWords){
            dp[word] = max(dp[word], 1);
            for(int i = 0; i < (int)word.length(); ++i){
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if(dp.count(predecessor)){
                    dp[word] = max(dp[word], 1 + dp[predecessor]);
                }
            }
            maxLen = max(maxLen, dp[word]);
        }
        
        return maxLen;
    }
};