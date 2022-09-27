class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        const int N = s.length();
        
        int res = 0;
        int zeros = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '0'){
                zeros += 1;
            }else if(zeros >= 1){
                res = max(res + 1, zeros);
            }
        }
        
        return res;
    }
};