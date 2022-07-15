class Solution {
public:
    bool digitCount(string s) {
        const int N = s.length();
        
        vector<int> count(10);
        for(char c: s){
            count[c - '0'] += 1;
        }
        
        for(int i = 0; i < N; ++i){
            if(s[i] - '0' != count[i]){
                return false;
            }
        }
        
        return true;
    }
};