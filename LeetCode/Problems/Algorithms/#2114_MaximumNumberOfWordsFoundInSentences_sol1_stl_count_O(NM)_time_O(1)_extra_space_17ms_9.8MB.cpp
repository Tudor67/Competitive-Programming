class Solution {    
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        for(const string& S: sentences){
            int words = 1 + count(S.begin(), S.end(), ' ');
            maxWords = max(maxWords, words);
        }
        return maxWords;
    }
};