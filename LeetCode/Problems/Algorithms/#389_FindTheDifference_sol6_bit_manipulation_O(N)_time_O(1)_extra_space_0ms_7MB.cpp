class Solution {
public:
    char findTheDifference(string s, string t) {
        int charDiffMask = 0;
        
        for(char c: s){
            charDiffMask ^= (1 << (c - 'a'));
        }

        for(char c: t){
            charDiffMask ^= (1 << (c - 'a'));
        }

        for(char c = 'a'; c <= 'z'; ++c){
            if((charDiffMask >> (c - 'a')) & 1){
                return c;
            }
        }

        return 0;
    }
};