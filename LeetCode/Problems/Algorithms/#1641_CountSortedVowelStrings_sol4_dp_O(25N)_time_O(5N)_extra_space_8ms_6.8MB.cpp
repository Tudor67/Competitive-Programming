class Solution {
public:
    int countVowelStrings(int n) {
        const vector<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
        
        vector<unordered_map<int, int>> dp(n + 1);
        for(int lastVowel: VOWELS){
            dp[1][lastVowel] = 1;
        }
        
        for(int len = 2; len <= n; ++len){
            for(char curVowel: VOWELS){
                for(char lastVowel: VOWELS){
                    if(lastVowel <= curVowel){
                        dp[len][curVowel] += dp[len - 1][lastVowel];
                    }
                }
            }
        }
        
        int answer = 0;
        for(char lastVowel: VOWELS){
            answer += dp[n][lastVowel];
        }
        
        return answer;
    }
};