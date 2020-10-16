class Solution {
public:
    int maxVowels(string s, int k) {
        const set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
        
        int answer = 0;
        int vowelsCnt = 0;
        for(int i = 0; i < s.length(); ++i){
            vowelsCnt += VOWELS.count(s[i]);
            if(i >= k){
                vowelsCnt -= VOWELS.count(s[i - k]);
            }
            answer = max(vowelsCnt, answer);
        }
        
        return answer;
    }
};