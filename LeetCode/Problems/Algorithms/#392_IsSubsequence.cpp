class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(int j = 0; j < t.length(); ++j){
            if(i < s.length() && s[i] == t[j]){
                ++i;
            }
        }
        return (i == s.length());
    }
};