class Solution {
private:
    static bool isVowel(char c){
        static const string VOWELS = "aeiou";
        return (VOWELS.find(c) != string::npos);
    }

public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        for(char c: s){
            freq[c] += 1;
        }

        int vowelMaxFreq = 0;
        int consonantMaxFreq = 0;
        for(const auto& [c, cFreq]: freq){
            if(isVowel(c)){
                vowelMaxFreq = max(vowelMaxFreq, cFreq);
            }else{
                consonantMaxFreq = max(consonantMaxFreq, cFreq);
            }
        }

        return vowelMaxFreq + consonantMaxFreq;
    }
};