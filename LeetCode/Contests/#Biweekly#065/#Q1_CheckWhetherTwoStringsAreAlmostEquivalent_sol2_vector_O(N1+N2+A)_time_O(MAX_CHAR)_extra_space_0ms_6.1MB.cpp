class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        const int MIN_CHAR = 'a';
        const int MAX_CHAR = 'z';
        
        vector<char> balance(MAX_CHAR + 1);
        
        for(char c: word1){
            balance[c] += 1;
        }
        
        for(char c: word2){
            balance[c] -= 1;
        }
        
        for(int c = MIN_CHAR; c <= MAX_CHAR; ++c){
            if(abs(balance[c]) >= 4){
                return false;
            }
        }
        
        return true;
    }
};