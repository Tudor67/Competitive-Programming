class Solution {
public:
    string removeOccurrences(string s, string part) {
        const int N = s.length();
        const int P = part.length();
        
        if(N < P){
            return s;
        }
        
        // kmp
        const string PS = part + "$" + s;
        const int L = PS.length();
        
        vector<int> p(L, 0);
        string res = {PS[0]};
        for(int idx = 1; idx < L; ++idx){
            char c = PS[idx];
            res.push_back(c);
            
            int i = (int)res.size() - 1;
            int k = p[i - 1];
            while(k > 0 && res[k] != c){
                k = p[k - 1];
            }
            
            if(res[k] == c){
                p[i] = k + 1;
            }else{
                p[i] = 0;
            }
            
            if(p[i] == P){
                res.resize((int)res.size() - P);
            }
        }
        
        return res.substr(P + 1);
    }
};