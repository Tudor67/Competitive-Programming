class Solution {
private:
    static bool incLenComp(const string& LHS, const string& RHS){
        return (LHS.length() < RHS.length());
    }
    
public:
    int longestStrChain(vector<string>& words) {
        const int N = words.size();
        
        vector<string> sortedWords = words;
        sort(sortedWords.begin(), sortedWords.end(), incLenComp);
        
        unordered_map<string, int> dp;
        for(int i = 0; i < N; ++i){
            dp[words[i]] = 1;
        }
        
        int answer = 0;
        for(int i = N - 1; i >= 0; --i){
            const string& WORD = sortedWords[i];
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