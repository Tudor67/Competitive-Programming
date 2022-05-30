class Solution {
private:
    bool isPrefix(const string& WORD, const string& S){
        const int WORD_LEN = WORD.length();
        const int S_LEN = S.length();
        return (WORD_LEN <= S_LEN && WORD.compare(0, WORD_LEN, S, 0, WORD_LEN) == 0);
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