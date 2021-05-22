class Solution {
public:
    int longestStrChain(vector<string>& words) {
        set<pair<int, string>> lengthWordSet;
        unordered_map<string, int> dp;
        for(const string& WORD: words){
            lengthWordSet.emplace(WORD.length(), WORD);
            dp[WORD] = 1;
        }
        
        int answer = 0;
        for(set<pair<int, string>>::const_reverse_iterator crit = lengthWordSet.crbegin(); crit != lengthWordSet.crend(); ++crit){
            const string& WORD = crit->second;
            answer = max(dp[WORD], answer);
            for(int i = 0; i < (int)WORD.length(); ++i){
                string nextWord = WORD.substr(0, i) + WORD.substr(i + 1);
                if(dp.count(nextWord)){
                    dp[nextWord] = max(1 + dp[WORD], dp[nextWord]);
                }
            }
        }
        
        return answer;
    }
};