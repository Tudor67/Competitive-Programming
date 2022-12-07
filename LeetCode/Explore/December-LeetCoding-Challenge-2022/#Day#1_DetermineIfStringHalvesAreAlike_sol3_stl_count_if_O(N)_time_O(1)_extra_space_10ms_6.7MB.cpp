class Solution {
private:
    static bool isVowel(char c){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
public:
    bool halvesAreAlike(string s) {
        const int N = s.length();
        int firstHalfVowels = count_if(s.begin(), s.begin() + N / 2, isVowel);
        int secondHalfVowels = count_if(s.begin() + N / 2, s.end(), isVowel);
        return (firstHalfVowels == secondHalfVowels);
    }
};