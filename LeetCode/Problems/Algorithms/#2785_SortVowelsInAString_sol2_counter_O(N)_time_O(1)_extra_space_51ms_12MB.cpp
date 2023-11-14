class Solution {
private:
    bool isVowel(char c){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    string sortVowels(string s) {
        const int N = s.length();

        map<char, int> freq;
        for(char c: s){
            if(isVowel(c)){
                freq[c] += 1;
            }
        }

        string res = s;
        for(int i = 0; i < N; ++i){
            if(isVowel(s[i])){
                char vowel = freq.begin()->first;
                freq[vowel] -= 1;
                if(freq[vowel] == 0){
                    freq.erase(vowel);
                }
                res[i] = vowel;
            }else{
                res[i] = s[i];
            }
        }

        return res;
    }
};