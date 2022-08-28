class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        const int A = 26;
        const int FIRST_CHAR = 'a';
        
        vector<int> balance(A);
        for(char c: magazine){
            balance[c - FIRST_CHAR] += 1;
        }
        
        for(char c: ransomNote){
            balance[c - FIRST_CHAR] -= 1;
        }
        
        for(char c = FIRST_CHAR; c < FIRST_CHAR + A; ++c){
            if(balance[c - FIRST_CHAR] < 0){
                return false;
            }
        }
        
        return true;
    }
};