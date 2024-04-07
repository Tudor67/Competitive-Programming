class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int N = s.length();

        unordered_map<char, char> f;
        unordered_map<char, char> fInv;
        
        for(int i = 0; i < N; ++i){
            if(f.count(s[i])){
                if(f[s[i]] != t[i]){
                    return false;
                }
            }else{
                if(!fInv.count(t[i]) || fInv[t[i]] == s[i]){
                    f[s[i]] = t[i];
                    fInv[t[i]] = s[i];
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};