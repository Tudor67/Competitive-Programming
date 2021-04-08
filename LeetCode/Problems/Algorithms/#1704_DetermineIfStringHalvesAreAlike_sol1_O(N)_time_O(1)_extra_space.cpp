class Solution {
private:
    bool isVowel(char c){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
public:
    bool halvesAreAlike(string s) {
        const int N = s.length();
        
        int leftVowelCount = 0;
        for(int i = 0; i < N / 2; ++i){
            leftVowelCount += isVowel(s[i]);
        }
        
        int rightVowelCount = 0;
        for(int i = N / 2; i < N; ++i){
            rightVowelCount += isVowel(s[i]);
        }
        
        return (leftVowelCount == rightVowelCount);
    }
};