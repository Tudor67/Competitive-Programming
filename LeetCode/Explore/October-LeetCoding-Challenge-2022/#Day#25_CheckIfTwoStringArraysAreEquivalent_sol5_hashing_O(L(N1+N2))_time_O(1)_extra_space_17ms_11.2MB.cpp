class Solution {
private:
    long long computeHash(const vector<string>& WORDS, const long long& BASE, const long long& MODULO){
        long long h = 0;
        for(const string& WORD: WORDS){
            for(char c: WORD){
                h = ((h * BASE) + c) % MODULO;
            }
        }
        return h;
    }
    
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        const long long MODULO1 = 1e9 + 7;
        const long long MODULO2 = 1e9 + 9;
        const long long BASE = 131;
        return (computeHash(word1, BASE, MODULO1) == computeHash(word2, BASE, MODULO1)) &&
               (computeHash(word1, BASE, MODULO2) == computeHash(word2, BASE, MODULO2));
    }
};