class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        
        const string S = s + s;
        const string P = goal;
        const string PS = P + "$" + S;
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
            if(p[i] == (int)P.length()){
                return true;
            }
        }
        
        return false;
    }
};