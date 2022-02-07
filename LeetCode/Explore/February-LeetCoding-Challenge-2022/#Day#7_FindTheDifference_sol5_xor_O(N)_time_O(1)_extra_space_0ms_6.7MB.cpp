class Solution {
public:
    char findTheDifference(string s, string t) {
        char extraChar = 0;
        
        for(char c: s){
            extraChar ^= c;
        }
        
        for(char c: t){
            extraChar ^= c;
        }
        
        return extraChar;
    }
};