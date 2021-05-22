class Solution {
private:
    int solve(const string& WORD, unordered_set<string>& wordSet, unordered_map<string, int>& memo){
        if(!memo.count(WORD)){
            int maxLen = 1;
            for(int i = 0; i < (int)WORD.length(); ++i){
                string nextWord = WORD.substr(0, i) + WORD.substr(i + 1);
                if(wordSet.count(nextWord)){
                    maxLen = max(1 + solve(nextWord, wordSet, memo), maxLen);
                }
            }
            memo[WORD] = maxLen;
        }
        return memo[WORD];
    }
    
public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        unordered_map<string, int> memo;
        int answer = 0;
        for(const string& WORD: words){
            answer = max(solve(WORD, wordSet, memo), answer);
        }
        return answer;
    }
};