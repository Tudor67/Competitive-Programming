class Solution {
public:
    int countSubstrings(string s, string t) {
        const int N = s.length();
        const int M = t.length();
        
        int answer = 0;
        for(int startPos = 0; startPos < N; ++startPos){
            for(int i = 0; i < M; ++i){
                int rightCnt = 0;
                int mismatchCnt = 0;
                for(int k = 0; mismatchCnt <= 1 && k + startPos < N && k + i < M; ++k){
                    if(s[k + startPos] == t[k + i]){
                        rightCnt += (mismatchCnt == 1);
                    }else{
                        mismatchCnt += 1;
                    }
                }
                answer += (mismatchCnt >= 1) * (1 + rightCnt);
            }
        }
        
        return answer;
    }
};