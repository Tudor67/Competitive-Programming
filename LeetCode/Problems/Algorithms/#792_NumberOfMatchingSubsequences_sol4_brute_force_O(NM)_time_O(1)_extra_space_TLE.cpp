class Solution {
private:
    bool isSubsequence(const string& WORD, const string& S){
        const int L = WORD.length();
        
        int k = 0;
        for(char c: S){
            if(k < L && WORD[k] == c){
                k += 1;
            }
        }
        
        return (k == L);
    }
    
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        const int N = s.length();
        const int M = words.size();
        
        int matchingSubsequences = 0;
        for(const string& WORD: words){
            if(isSubsequence(WORD, s)){
                matchingSubsequences += 1;
            }
        }
        
        return matchingSubsequences;
    }
};