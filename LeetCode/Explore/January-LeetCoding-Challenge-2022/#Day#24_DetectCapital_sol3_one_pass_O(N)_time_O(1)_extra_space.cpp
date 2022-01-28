class Solution {
public:
    bool detectCapitalUse(string word) {
        const int N = word.length();
        int capitals = 0;
        for(char c: word){
            if(isupper(c)){
                capitals += 1;
            }
        }
        return (capitals == 0 || capitals == N || (capitals == 1 && isupper(word[0])));
    }
};