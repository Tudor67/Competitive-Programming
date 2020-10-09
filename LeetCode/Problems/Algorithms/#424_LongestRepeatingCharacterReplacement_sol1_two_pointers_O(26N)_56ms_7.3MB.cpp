class Solution {
public:
    int characterReplacement(string s, int k) {
        const int N = s.length();
        
        int answer = 0;
        for(char c = 'A'; c <= 'Z'; ++c){
            int replacements = 0;
            for(int i = 0, j = 0; j < N; ++j){
                if(c != s[j]){
                    replacements += 1;
                }
                while(replacements > k){
                    replacements -= (c != s[i]);
                    i += 1;
                }
                answer = max(j - i + 1, answer);
            }
        }
        
        return answer;
    }
};