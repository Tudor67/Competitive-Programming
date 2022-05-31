class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int N = s.length();
        const int TOTAL_MASKS = (1 << k);
        const int FULL_MASK = (1 << k) - 1;
        
        if(N - k + 1 < TOTAL_MASKS){
            return false;
        }
        
        vector<bool> vis(FULL_MASK + 1, false);
        int mask = 0;
        for(int i = 0; i < N; ++i){
            mask = (2 * mask + (s[i] - '0')) & FULL_MASK;
            if(i >= k - 1){
                vis[mask] = true;
            }
        }
        
        return (count(vis.begin(), vis.end(), true) == TOTAL_MASKS);
    }
};