class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int N = s.length();
        
        unordered_set<char> sSet(s.begin(), s.end());
        unordered_set<char> tSet(t.begin(), t.end());
        
        unordered_set<string> stSet;
        for(int i = 0; i < N; ++i){
            stSet.insert(string(1, s[i]) + string(1, t[i]));
        }
        
        return (sSet.size() == tSet.size() && tSet.size() == stSet.size());
    }
};