class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        const int N = s.length();
        const int INITIAL_ONES = count(s.begin(), s.end(), '1');

        int res = INITIAL_ONES;
        int prevG0 = 0;
        
        int l = 0;
        while(l < N){
            if(s[l] == '0'){
                int r = l;
                while(r < N && s[r] == '0'){
                    r += 1;
                }
                int currG0 = r - l;
                if(prevG0 > 0){
                    res = max(res, INITIAL_ONES + prevG0 + currG0);
                }
                l = r;
                prevG0 = currG0;
            }else{
                l += 1;
            }
        }

        return res;
    }
};