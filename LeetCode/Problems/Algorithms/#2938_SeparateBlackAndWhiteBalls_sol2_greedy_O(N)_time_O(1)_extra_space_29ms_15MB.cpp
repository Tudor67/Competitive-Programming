class Solution {
public:
    long long minimumSteps(string s) {
        const int N = s.length();
        
        long long res = 0;
        int ones = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '0'){
                res += ones;
            }else{
                ones += 1;
            }
        }
        
        return res;
    }
};