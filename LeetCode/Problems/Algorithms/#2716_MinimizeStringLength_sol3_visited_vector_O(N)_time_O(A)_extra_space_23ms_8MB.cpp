class Solution {
public:
    int minimizedStringLength(string s) {
        const int A = 26;

        int distinctChars = 0;
        vector<bool> vis(A, false);
        for(char c: s){
            if(!vis[c - 'a']){
                distinctChars += 1;
            }
            vis[c - 'a'] = true;
        }

        return distinctChars;
    }
};