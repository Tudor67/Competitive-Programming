class Solution {
public:
    long long minimumSteps(string s) {
        const int N = s.length();
        
        long long res = 0;
        int prefZeros = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '0'){
                res += i - prefZeros;
                prefZeros += 1;
            }
        }
        
        return res;
    }
};