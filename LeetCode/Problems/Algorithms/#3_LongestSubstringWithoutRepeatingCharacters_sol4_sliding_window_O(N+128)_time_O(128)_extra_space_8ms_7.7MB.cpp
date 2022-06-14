class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int N = s.length();
        
        int maxLen = 0;
        int i = 0;
        vector<int> count(128);
        for(int j = 0; j < N; ++j){
            count[s[j]] += 1;
            while(count[s[j]] >= 2){
                count[s[i]] -= 1;
                i += 1;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        
        return maxLen;
    }
};