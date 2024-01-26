class Solution {
private:
    bool isVowel(char c){
        static const unordered_set<char> VOWELS_SET = {'a', 'e', 'i', 'o', 'u'};
        return (VOWELS_SET.find(tolower(c)) != VOWELS_SET.end());
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

        string t = s;
        for(int i = 0; i < N; ++i){
            if(isVowel(t[i])){
                t[i] = freq.begin()->first;
                freq.begin()->second -= 1;
                if(freq.begin()->second == 0){
                    freq.erase(freq.begin());
                }
            }
        }

        return t;
    }
};