class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int N = s.length();
        const int M = t.length();
        
        int i = 0;
        for(int j = 0; j < M; ++j){
            if(i < N && s[i] == t[j]){
                ++i;
            }
        }
        
        return (i == N);
    }
};