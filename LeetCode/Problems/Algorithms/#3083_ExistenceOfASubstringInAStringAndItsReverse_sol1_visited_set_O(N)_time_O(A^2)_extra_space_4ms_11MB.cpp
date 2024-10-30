class Solution {
public:
    bool isSubstringPresent(string s) {
        const int N = s.length();

        set<string> vis;
        for(int i = 0; i + 1 < N; ++i){
            vis.insert(s.substr(i, 2));
        }
        
        for(int i = 0; i + 1 < N; ++i){
            if(vis.count(string(1, s[i + 1]) + string(1, s[i]))){
                return true;
            }
        }
        
        return false;
    }
};