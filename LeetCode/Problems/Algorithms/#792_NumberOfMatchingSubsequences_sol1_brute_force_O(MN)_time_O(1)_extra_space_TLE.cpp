class Solution {
private:
    bool isSubsequence(const string& WORD, const string& S){
        const int L = WORD.length();
        int pos = 0;
        for(char c: S){
            if(c == WORD[pos]){
                pos += 1;
            }
            if(pos == L){
                return true;
            }
        }
        return false;
    }
    
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        const int N = s.length();
        const int M = words.size();
        
        int subsequenceCount = 0;
        for(const string& WORD: words){
            subsequenceCount += isSubsequence(WORD, s);
        }
        
        return subsequenceCount;
    }
};