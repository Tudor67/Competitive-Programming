class Solution {
public:
    int countGoodSubstrings(string s) {
        const int N = s.length();
        
        int answer = 0;
        for(int i = 0; i + 2 < N; ++i){
            if(s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]){
                answer += 1;
            }
        }
        
        return answer;
    }
};