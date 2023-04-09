class Solution {
public:
    int partitionString(string s) {
        const int N = s.length();
        const int A = 26;
        const int FIRST_CHAR = 'a';

        int res = 1;
        vector<bool> vis(A, false);
        for(char c: s){
            if(vis[c - FIRST_CHAR]){
                res += 1;
                fill(vis.begin(), vis.end(), false);
            }
            vis[c - FIRST_CHAR] = true;
        }

        return res;
    }
};