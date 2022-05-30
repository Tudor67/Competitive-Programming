class Solution {
private:
    bool isPrefix(const string& WORD, const string& S){
        const int WORD_LEN = WORD.length();
        const int S_LEN = S.length();
        int i = 0;
        while(i < WORD_LEN && i < S_LEN){
            if(WORD[i] == S[i]){
                i += 1;
            }else{
                break;
            }
        }
        return (i == WORD_LEN);
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