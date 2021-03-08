class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        
        for(const string& WORD: words){
            for(int j = 1; j < (int)WORD.length(); ++j){
                wordSet.erase(WORD.substr(j));
            }
        }
        
        int answer = 0;
        for(const string& WORD: wordSet){
            answer += WORD.length() + 1;
        }
        
        return answer;
    }
};