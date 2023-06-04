class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        const int N = s.length();
        
        int res = 0;
        int startPos = 0;
        while(startPos < N){
            int zeros = 0;
            int endPos = startPos;
            while(endPos < N && s[endPos] == '0'){
                zeros += 1;
                endPos += 1;
            }

            int ones = 0;
            while(endPos < N && s[endPos] == '1'){
                ones += 1;
                endPos += 1;
            }

            int balancedStrLen = 2 * min(zeros, ones);

            res = max(res, balancedStrLen);

            startPos = endPos;
        }

        return res;
    }
};