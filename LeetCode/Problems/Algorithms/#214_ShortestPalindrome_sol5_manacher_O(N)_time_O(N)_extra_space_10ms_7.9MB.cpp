class Solution {
public:
    string shortestPalindrome(string originalStr) {
        string s = ".";
        for(char c: originalStr){
            s += c;
            s += '.';
        }
        
        vector<int> r(s.length());
        int rMaxIdx = 0;
        int maxPalindromePrefixLength = 0;
        for(int i = 1; i < (int)s.length(); ++i){
            if(i <= rMaxIdx + r[rMaxIdx]){
                r[i] = min(r[rMaxIdx - (i - rMaxIdx)], (rMaxIdx + r[rMaxIdx]) - i);
            }
            while(0 <= i - r[i] - 1 && i + r[i] + 1 < s.length() && s[i - r[i] - 1] == s[i + r[i] + 1]){
                r[i] += 1;
            }
            if(i + r[i] >= rMaxIdx + r[rMaxIdx]){
                rMaxIdx = i;
            }
            if(r[i] == i){
                maxPalindromePrefixLength = i;
            }
        }
        
        return string(originalStr.rbegin(), originalStr.rbegin() + (int)originalStr.length() - maxPalindromePrefixLength) + originalStr;
    }
};