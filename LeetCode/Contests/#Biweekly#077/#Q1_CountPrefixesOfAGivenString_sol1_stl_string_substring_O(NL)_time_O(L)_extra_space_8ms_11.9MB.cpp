class Solution {
private:
    bool isPrefix(const string& WORD, const string& S){
        const int WORD_LEN = WORD.length();
        return (WORD == S.substr(0, WORD_LEN));
    }
    
public:
    int countPrefixes(vector<string>& words, string s) {
        const int N = words.size();
        
        int count = 0;
        for(const string& WORD: words){
            if(isPrefix(WORD, s)){
                count += 1;
            }
        }
        
        return count;
    }
};