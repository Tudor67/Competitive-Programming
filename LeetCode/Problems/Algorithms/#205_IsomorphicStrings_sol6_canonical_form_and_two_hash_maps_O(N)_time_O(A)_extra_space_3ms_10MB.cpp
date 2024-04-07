class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int N = s.length();

        int sIndex = 0;
        int tIndex = 0;
        unordered_map<char, int> sIndexOf;
        unordered_map<char, int> tIndexOf;
        
        for(int i = 0; i < N; ++i){
            if(!sIndexOf.count(s[i])){
                sIndexOf[s[i]] = sIndex;
                sIndex += 1;
            }
            if(!tIndexOf.count(t[i])){
                tIndexOf[t[i]] = tIndex;
                tIndex += 1;
            }
            if(sIndexOf[s[i]] != tIndexOf[t[i]]){
                return false;
            }
        }

        return true;
    }
};