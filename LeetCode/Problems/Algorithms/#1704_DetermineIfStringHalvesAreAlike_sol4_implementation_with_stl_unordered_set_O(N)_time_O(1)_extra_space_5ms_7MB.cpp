class Solution {
private:
    bool isVowel(char c){
        static const unordered_set<char> VOWELS_SET = {'a', 'e', 'i', 'o', 'u'};
        return VOWELS_SET.find(tolower(c)) != VOWELS_SET.end();
    }

    int countVowels(string& s, int firstPos, int lastPos){
        int vowels = 0;
        for(int i = firstPos; i <= lastPos; ++i){
            vowels += isVowel(s[i]);
        }
        return vowels;
    }

public:
    bool halvesAreAlike(string s) {
        const int N = s.length();
        return (countVowels(s, 0, N / 2 - 1) == countVowels(s, N / 2, N - 1));
    }
};