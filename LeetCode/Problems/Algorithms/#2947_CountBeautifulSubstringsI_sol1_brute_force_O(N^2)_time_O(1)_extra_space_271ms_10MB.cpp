class Solution {
private:
    bool isVowel(char c){
        static const string VOWELS = "aeiou";
        return (VOWELS.find(c) != string::npos);
    }
    
public:
    int beautifulSubstrings(string s, int k) {
        const int N = s.length();
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            int vowels = 0;
            for(int j = i; j < N; ++j){
                vowels += isVowel(s[j]);
                int consonants = j - i + 1 - vowels;
                if(vowels == consonants && (vowels * consonants) % k == 0){
                    res += 1;
                }
            }
        }
        
        return res;
    }
};