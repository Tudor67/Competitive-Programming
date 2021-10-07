class Solution {
public:
    int distinctEchoSubstrings(string text) {
        const int N = text.length();
        
        unordered_set<string> substrSet;
        for(int len = 1; 2 * len <= N; ++len){
            int matchCount = 0;
            for(int i = 0; i < len; ++i){
                matchCount += (text[i] == text[i + len]);
            }
            if(matchCount == len){
                substrSet.insert(text.substr(0, len));
            }
            
            for(int i = 1; i + 2 * len - 1 < N; ++i){
                matchCount -= (text[i - 1] == text[i + len - 1]);
                matchCount += (text[i + len - 1] == text[i + 2 * len - 1]);
                if(matchCount == len){
                    substrSet.insert(text.substr(i, len));
                }
            }
        }
        
        return substrSet.size();
    }
};