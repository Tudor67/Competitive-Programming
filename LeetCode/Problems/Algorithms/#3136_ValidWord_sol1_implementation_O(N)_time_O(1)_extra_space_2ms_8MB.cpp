class Solution {
private:
    bool isVowel(char c){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    bool isConsonant(char c){
        return isalpha(c) && !isVowel(c);
    }

public:
    bool isValid(string word) {
        bool containsVowel = false;
        bool containsConsonant = false;
        bool containsSpecialChars = false;

        for(char c: word){
            if(isdigit(c)){
                // ignore digits
            }else if(isVowel(c)){
                containsVowel = true;
            }else if(isConsonant(c)){
                containsConsonant = true;
            }else{
                containsSpecialChars = true;
            }
        }

        return ((int)word.length() >= 3 && containsVowel && containsConsonant && !containsSpecialChars);
    }
};