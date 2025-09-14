class Solution {
private:
    static bool isVowel(char c){
        static const string VOWELS = "aeiou";
        return (VOWELS.find(c) != string::npos);
    }

public:
    bool doesAliceWin(string s) {
        int vowelsCount = 0;
        for(char c: s){
            if(isVowel(c)){
                vowelsCount += 1;
            }
        }
        return (vowelsCount >= 1);
    }
};