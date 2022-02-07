class Solution {
public:
    char findTheDifference(string s, string t) {
        int mask = 0;
        for(char c: s){
            mask ^= (1 << (c - 'a'));
        }
        
        for(char c: t){
            mask ^= (1 << (c - 'a'));
        }
        
        for(int bit = 0; bit < 26; ++bit){
            if((mask >> bit) & 1){
                return char('a' + bit);
            }
        }
        
        return -1;
    }
};