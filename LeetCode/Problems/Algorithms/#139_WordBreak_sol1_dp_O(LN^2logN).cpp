class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int N = s.length();
        s = "#" + s;
        
        set<string> words;
        for(string word: wordDict){
            words.insert(word);
        }
        
        vector<bool> canBeSegmented(N, false);
        canBeSegmented[0] = true;
        for(int i = 1; i <= N; ++i){
            for(int j = 0; j <= i - 1; ++j){
                if(canBeSegmented[j] && words.find(s.substr(j + 1, i - j)) != words.end()){
                    canBeSegmented[i] = true;
                    break;
                }
            }
        }
        
        return canBeSegmented[N];
    }
};