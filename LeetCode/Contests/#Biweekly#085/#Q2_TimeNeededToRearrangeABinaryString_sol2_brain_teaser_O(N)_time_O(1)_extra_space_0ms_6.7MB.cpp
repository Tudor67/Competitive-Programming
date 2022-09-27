class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        const int N = s.length();
        
        int res = 0;
        int zeros = 0;
        int waitingTime = 0;
        for(int i = 0; i < N; ++i){
            if(i >= 1 && s[i - 1] == '0' && s[i] == '0' && waitingTime >= 1){
                waitingTime -= 1;
            }
            if(i >= 1 && s[i - 1] == '1' && s[i] == '1' && zeros >= 1){
                waitingTime += 1;
            }
            if(s[i] == '0'){
                zeros += 1;
            }
            if(s[i] == '1' && zeros >= 1){
                res = zeros + waitingTime;
            }
        }
        
        return res;
    }
};