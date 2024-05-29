class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        const int N = s.length();

        int maxLen = 0;
        int cost = 0;
        int l = 0;
        
        for(int r = 0; r < N; ++r){
            cost += abs(s[r] - t[r]);
            while(l <= r && cost > maxCost){
                cost -= abs(s[l] - t[l]);
                l += 1;
            }
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};