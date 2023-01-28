class Solution {
private:
    bool isConcatentationOfAtLeastTwoWords(const string& WORD, unordered_set<string>& wordsSet){
        const int L = WORD.length();

        vector<int> dp(L);
        for(int i = 0; i < L; ++i){
            if(i == 0 || dp[i - 1] >= 1){
                string lastWord;
                for(int j = i; j < L; ++j){
                    lastWord += WORD[j];
                    if(wordsSet.count(lastWord)){
                        dp[j] = max(dp[j], (i == 0 ? 1 : dp[i - 1] + 1));
                    }
                }
            }
            if(dp[L - 1] >= 2){
                return true;
            }
        }

        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        const int N = words.size();

        vector<string> res;
        unordered_set<string> wordsSet(words.begin(), words.end());
        for(const string& WORD: words){
            if(isConcatentationOfAtLeastTwoWords(WORD, wordsSet)){
                res.push_back(WORD);
            }
        }

        return res;
    }
};