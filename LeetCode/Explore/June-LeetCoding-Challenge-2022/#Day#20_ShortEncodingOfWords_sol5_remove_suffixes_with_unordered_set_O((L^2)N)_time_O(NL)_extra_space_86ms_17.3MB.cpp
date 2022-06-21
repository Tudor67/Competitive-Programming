class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> resWordSet(words.begin(), words.end());
        
        for(const string& WORD: words){
            for(int suffixStartIdx = 1; suffixStartIdx < (int)WORD.length(); ++suffixStartIdx){
                string suffix = WORD.substr(suffixStartIdx);
                resWordSet.erase(suffix);
            }
        }
        
        int res = 0;
        for(const string& WORD: resWordSet){
            res += WORD.length();
            res += 1;
        }
        
        return res;
    }
};