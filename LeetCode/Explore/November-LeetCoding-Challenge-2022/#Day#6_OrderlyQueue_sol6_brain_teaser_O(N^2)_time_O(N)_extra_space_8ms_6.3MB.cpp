class Solution {
public:
    string orderlyQueue(string s, int k) {
        const int N = s.length();
        
        string res;
        if(k == 1){
            int resStartPos = 0;
            string ss = s + s;
            for(int i = 1; i < N; ++i){
                if(ss.compare(i, N, ss, resStartPos, N) < 0){
                    resStartPos = i;
                }
            }
            res = ss.substr(resStartPos, N);
        }else{
            res = s;
            sort(res.begin(), res.end());
        }
        
        return res;
    }
};