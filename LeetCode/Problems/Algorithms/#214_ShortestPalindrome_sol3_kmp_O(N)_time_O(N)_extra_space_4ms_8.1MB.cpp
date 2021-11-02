class Solution {
public:
    string shortestPalindrome(string s) {
        if((int)s.length() <= 1){
            return s;
        }
        
        const int N = s.length();
        const string REV_S(s.rbegin(), s.rend());
        const string P = s;
        const string PS = P + "$" + REV_S;
        const int L = PS.length();
        
        vector<int> p(L, 0);
        for(int i = 1; i < L; ++i){
            int k = p[i - 1];
            while(k > 0 && PS[k] != PS[i]){
                k = p[k - 1];
            }
            if(PS[k] == PS[i]){
                p[i] = k + 1;
            }
        }
        
        return REV_S.substr(0, N - p[L - 1]) + s;
    }
};