class Solution {
public:
    bool checkIfPangram(string sentence) {
        const int A = 26;
        const int FIRST_CHAR = 'a';
        
        vector<bool> vis(A, false);
        for(char c: sentence){
            vis[c - FIRST_CHAR] = true;
        }
        
        return count(vis.begin(), vis.end(), true) == A;
    }
};