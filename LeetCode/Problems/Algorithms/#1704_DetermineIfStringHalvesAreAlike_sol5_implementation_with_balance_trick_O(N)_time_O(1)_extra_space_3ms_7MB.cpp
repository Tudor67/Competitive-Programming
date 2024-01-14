class Solution {
private:
    bool isVowel(char c){
        static const unordered_set<char> VOWELS_SET = {'a', 'e', 'i', 'o', 'u'};
        return VOWELS_SET.find(tolower(c)) != VOWELS_SET.end();
    }

public:
    bool halvesAreAlike(string s) {
        const int N = s.length();
        
        int balance = 0;
        for(int i = 0; i < N; ++i){
            if(isVowel(s[i])){
                if(i < N / 2){
                    balance += 1;
                }else{
                    balance -= 1;
                }
            }
        }

        return (balance == 0);
    }
};