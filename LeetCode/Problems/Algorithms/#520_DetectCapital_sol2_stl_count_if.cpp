class Solution {
public:
    bool detectCapitalUse(string word) {
        const int N = word.length();
        int up_cnt = count_if(word.begin(), word.end(), ::isupper);
        return (up_cnt == 0 || up_cnt == N || (up_cnt == 1 && isupper(word[0])));
    }
};