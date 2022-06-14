class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int N = s.length();
        
        int maxLen = 0;
        vector<bool> vis(128);
        for(int i = 0; i < N; ++i){
            fill(vis.begin(), vis.end(), false);
            int j = i;
            while(j < N && !vis[s[j]]){
                vis[s[j]] = true;
                j += 1;
            }
            maxLen = max(maxLen, j - i);
        }
        
        return maxLen;
    }
};