class Solution {
public:
    bool isAnagram(string s, string t) {
        const int A = 26;
        const char FIRST_CHAR = 'a';
        
        vector<int> balance(A);
        
        for(char c: s){
            balance[c - FIRST_CHAR] += 1;
        }
        
        for(char c: t){
            balance[c - FIRST_CHAR] -= 1;
        }
        
        for(char c = FIRST_CHAR; c < FIRST_CHAR + A; ++c){
            if(balance[c - FIRST_CHAR] != 0){
                return false;
            }
        }
        
        return true;
    }
};