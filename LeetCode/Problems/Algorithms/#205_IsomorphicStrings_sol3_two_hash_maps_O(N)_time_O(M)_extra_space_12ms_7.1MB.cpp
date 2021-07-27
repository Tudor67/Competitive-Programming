class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int N = s.length();
        unordered_map<char, char> sMapT;
        unordered_map<char, char> tMapS;
        for(int i = 0; i < N; ++i){
            if(!sMapT.count(s[i]) && !tMapS.count(t[i])){
                sMapT[s[i]] = t[i];
                tMapS[t[i]] = s[i];
            }else if(!(sMapT.count(s[i]) && sMapT[s[i]] == t[i] && tMapS.count(t[i]) && tMapS[t[i]] == s[i])){
                return false;
            }
        }
        return true;
    }
};