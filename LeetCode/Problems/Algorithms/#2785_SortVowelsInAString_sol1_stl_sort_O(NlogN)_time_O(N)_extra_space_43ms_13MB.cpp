class Solution {
private:
    bool isVowel(char c){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    string sortVowels(string s) {
        const int N = s.length();

        string sortedVowels;
        for(char c: s){
            if(isVowel(c)){
                sortedVowels.push_back(c);
            }
        }

        sort(sortedVowels.begin(), sortedVowels.end());

        string res = s;
        for(int i = N - 1; i >= 0; --i){
            if(isVowel(s[i])){
                res[i] = sortedVowels.back();
                sortedVowels.pop_back();
            }else{
                res[i] = s[i];
            }
        }

        return res;
    }
};