class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.length();
        
        // isPalindrome[len][i]: true, if s[i][i + len - 1] is palindrome
        //                       false, otherwise
        vector<vector<bool>> isPalindrome(N + 1, vector<bool>(N, false));
        int startIdx = 0;
        int maxLen = 0;
        for(int len = 1; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                if(s[i] == s[i + len - 1] && (len <= 2 || isPalindrome[len - 2][i + 1])){
                    isPalindrome[len][i] = true;
                }
                if(len > maxLen && isPalindrome[len][i]){
                    startIdx = i;
                    maxLen = len;
                }
            }
        }
        
        return s.substr(startIdx, maxLen);
    }
};