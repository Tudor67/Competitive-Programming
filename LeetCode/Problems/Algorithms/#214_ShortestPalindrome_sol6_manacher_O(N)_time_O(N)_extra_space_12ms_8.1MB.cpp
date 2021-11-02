class Solution {
public:
    string shortestPalindrome(string originalStr) {
        string s = ".";
        for(char c: originalStr){
            s += c;
            s += '.';
        }
        
        const int L = s.length();
        vector<int> radius(L);
        int l = 0;
        int r = 0;
        int maxPalindromePrefixLength = 0;
        for(int i = 1; i < L; ++i){
            if(i <= r){
                radius[i] = min(radius[l + r - i], r - i);
            }
            while(0 <= i - radius[i] - 1 && i + radius[i] + 1 < L && s[i - radius[i] - 1] == s[i + radius[i] + 1]){
                radius[i] += 1;
            }
            if(i + radius[i] >= r){
                l = i - radius[i];
                r = i + radius[i];
            }
            if(radius[i] == i){
                maxPalindromePrefixLength = i;
            }
        }
        
        return string(originalStr.rbegin(), originalStr.rbegin() + (int)originalStr.length() - maxPalindromePrefixLength) + originalStr;
    }
};