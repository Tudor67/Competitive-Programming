class Solution {
public:
    bool detectCapitalUse(string word) {
        const int N = word.length();

        int upCount = 0;
        for(char c: word){
            if(isupper(c)){
                upCount += 1;
            }
        }

        return (upCount == 0 || upCount == N || (upCount == 1 && isupper(word[0])));
    }
};