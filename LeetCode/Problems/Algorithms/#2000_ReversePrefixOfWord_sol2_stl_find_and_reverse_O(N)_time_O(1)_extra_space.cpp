class Solution {
public:
    string reversePrefix(string word, char ch) {
        const int N = word.length();
        int pos = find(word.begin(), word.end(), ch) - word.begin();
        if(pos != N){
            reverse(word.begin(), word.begin() + pos + 1);
        }
        return word;
    }
};