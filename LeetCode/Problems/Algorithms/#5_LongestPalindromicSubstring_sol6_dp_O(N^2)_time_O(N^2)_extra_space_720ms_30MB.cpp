class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.length();
        
        // isPalindrome[i][j]: true, if s[i .. j] is palindrome
        //                     false, otherwise
        vector<vector<bool>> isPalindrome(N, vector<bool>(N, false));
        int startIdx = 0;
        int maxLen = 0;
        for(int len = 1; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                int j = i + len - 1;
                if(s[i] == s[j] && (i + 1 >= j - 1 || isPalindrome[i + 1][j - 1])){
                    isPalindrome[i][j] = true;
                }
                if(len > maxLen && isPalindrome[i][j]){
                    startIdx = i;
                    maxLen = len;
                }
            }
        }
        
        return s.substr(startIdx, maxLen);
    }
};