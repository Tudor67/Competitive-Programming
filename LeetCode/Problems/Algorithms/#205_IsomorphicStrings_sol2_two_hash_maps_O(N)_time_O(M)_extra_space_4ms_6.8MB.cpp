class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int N = s.length();
        
        unordered_map<char, int> sIdxOf;
        unordered_map<char, int> tIdxOf;
        int sIdx = -1;
        int tIdx = -1;
        for(int i = 0; i < N; ++i){
            if(!sIdxOf.count(s[i])){
                sIdxOf[s[i]] = ++sIdx;
            }
            if(!tIdxOf.count(t[i])){
                tIdxOf[t[i]] = ++tIdx;
            }
            if(sIdxOf[s[i]] != tIdxOf[t[i]]){
                return false;
            }
        }
        
        return true;
    }
};