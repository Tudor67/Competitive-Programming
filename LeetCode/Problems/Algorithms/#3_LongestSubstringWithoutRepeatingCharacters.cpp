class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best_sol = 0;
        int cur_sol = 0;
        vector<bool> vis(256, false);
        
        int i = 0;
        int j = 0;
        while(j < s.length()){
            while(j < s.length() && !vis[s[j]]){
                vis[s[j]] = true;
                ++j;
            }
            cur_sol = j - i;
            best_sol = max(cur_sol, best_sol);
            
            vis[s[i]] = false;
            ++i;
        }
        
        return best_sol;
    }
};