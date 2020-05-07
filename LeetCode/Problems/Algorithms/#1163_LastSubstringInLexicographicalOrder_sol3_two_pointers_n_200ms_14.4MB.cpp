class Solution {
public:
    string lastSubstring(string s) {
        const int N = s.length();
        
        int i = 0, j = 1, k = 0;
        while(j + k < N){
            if(s[i + k] == s[j + k]){ ++k; }
            else if(s[i + k] < s[j + k]){ i = j; k = 0; ++j; }
            else if(s[i + k] > s[j + k]){ k = 0; ++j; }
        }
        
        return s.substr(i);
    }
};