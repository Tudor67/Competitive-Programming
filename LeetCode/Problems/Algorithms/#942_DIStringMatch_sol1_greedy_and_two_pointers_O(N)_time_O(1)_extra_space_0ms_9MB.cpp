class Solution {
public:
    vector<int> diStringMatch(string s) {
        const int N = s.length();
        
        vector<int> res(N + 1);
        int incVal = 0;
        int decVal = N;
        for(int i = 0; i < N; ++i){
            if(s[i] == 'I'){
                res[i] = incVal;
                ++incVal;
            }else{
                res[i] = decVal;
                --decVal;
            }
        }
        
        res[N] = incVal;
        
        return res;
    }
};