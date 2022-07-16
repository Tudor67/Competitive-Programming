class Solution {
private:
    bool isMatchingWithReplacement(string& s, int i, string& sub, vector<vector<bool>>& canReplace){
        const int M = sub.length();
        for(int j = 0; j < M; ++j){
            if(s[i + j] != sub[j] && !canReplace[sub[j]][s[i + j]]){
                return false;
            }
        }
        return true;
    }
    
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        const int N = s.length();
        const int M = sub.length();
        
        vector<vector<bool>> canReplace(130, vector<bool>(130, false));
        for(const vector<char>& MAPPING: mappings){
            char oldChar = MAPPING[0];
            char newChar = MAPPING[1];
            canReplace[oldChar][newChar] = true;
        }
        
        for(int i = 0; i + M - 1 < N; ++i){
            if(isMatchingWithReplacement(s, i, sub, canReplace)){
                return true;
            }
        }
        
        return false;
    }
};