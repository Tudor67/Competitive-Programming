class Solution {
public:
    int countGoodSubstrings(string s) {
        const int N = s.length();
        const int K = 3;
        
        vector<int> count(128);
        int distinctChars = 0;
        int answer = 0;
        for(int i = 0; i < N; ++i){
            count[s[i]] += 1;
            distinctChars += (int)(count[s[i]] == 1);
            if(i >= K){
                distinctChars -= (int)(count[s[i - K]] == 1);
                count[s[i - K]] -= 1;
            }
            if(distinctChars == K){
                answer += 1;
            }
        }
        
        return answer;
    }
};