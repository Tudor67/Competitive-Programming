class Solution {
public:
    bool detectCapitalUse(string word) {
        const int N = word.length();
        int upCount = count_if(word.begin(), word.end(), ::isupper);
        return (upCount == 0 || upCount == N || (upCount == 1 && isupper(word[0])));
    }
};