class Solution {
private:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
public:
    int maxVowels(string s, int k) {
        int answer = 0;
        int vowelsCnt = 0;
        for(int i = 0; i < s.length(); ++i){
            vowelsCnt += isVowel(s[i]);
            if(i >= k){
                vowelsCnt -= isVowel(s[i - k]);
            }
            answer = max(vowelsCnt, answer);
        }
        return answer;
    }
};