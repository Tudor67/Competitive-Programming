class Solution {
private:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    int maxVowels(string s, int k) {
        const int N = s.length();

        int res = 0;
        int vowels = 0;
        for(int i = 0; i < N; ++i){
            vowels += (int)isVowel(s[i]);
            if(i >= k){
                vowels -= (int)isVowel(s[i - k]);
            }
            res = max(res, vowels);
        }

        return res;
    }
};