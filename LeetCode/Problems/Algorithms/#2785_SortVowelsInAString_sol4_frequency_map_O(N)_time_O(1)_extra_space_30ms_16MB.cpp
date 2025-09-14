class Solution {
private:
    bool isVowel(char c){
        static const string VOWELS = "aeiou";
        c = tolower(c);
        return (VOWELS.find(c) != string::npos);
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

        string res(N, '.');
        for(int i = 0; i < N; ++i){
            if(isVowel(s[i])){
                res[i] = freq.begin()->first;
                freq[res[i]] -= 1;
                if(freq[res[i]] == 0){
                    freq.erase(res[i]);
                }
            }else{
                res[i] = s[i];
            }
        }

        return res;
    }
};