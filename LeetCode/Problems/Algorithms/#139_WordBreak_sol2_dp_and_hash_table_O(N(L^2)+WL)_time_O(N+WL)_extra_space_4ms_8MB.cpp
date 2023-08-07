class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int N = s.length();
        const int W = wordDict.size();

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        int wordMaxLen = 0;
        for(const string& WORD: wordDict){
            wordMaxLen = max(wordMaxLen, (int)WORD.length());
        }

        // isPossible[i]: true, if is possible to segment s[i .. N - 1]
        //                false, otherwise
        vector<bool> isPossible(N + 1, false);
        isPossible[N] = true;

        for(int i = N - 1; i >= 0; --i){
            string w;
            for(int j = i; j < min(i + wordMaxLen, N); ++j){
                w += s[j];
                if(isPossible[j + 1] && wordSet.count(w)){
                    isPossible[i] = true;
                    break;
                }
            }
        }

        return isPossible[0];
    }
};