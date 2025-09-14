class Solution {
private:
    static bool isVowel(char c){
        static const string VOWELS = "aeiou";
        return (VOWELS.find(c) != string::npos);
    }
    
public:
    bool doesAliceWin(string s) {
        return (find_if(s.begin(), s.end(), isVowel) != s.end());
    }
};