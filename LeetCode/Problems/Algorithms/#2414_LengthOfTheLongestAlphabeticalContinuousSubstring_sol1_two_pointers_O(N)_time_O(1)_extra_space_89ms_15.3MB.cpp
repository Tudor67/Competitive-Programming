class Solution {
public:
    int longestContinuousSubstring(string s) {
        const int N = s.length();
        
        int maxLen = 0;
        int startPos = 0;
        while(startPos < N){
            int endPos = startPos + 1;
            while(endPos < N && s[endPos - 1] + 1 == s[endPos]){
                endPos += 1;
            }
            maxLen = max(maxLen, endPos - startPos);
            startPos = endPos;
        }
        
        return maxLen;
    }
};