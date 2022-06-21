class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.length();
        
        // At step len:
        //    isPalindrome[len % 3][i]: true, if s[i][i + len - 1] is palindrome
        //                              false, otherwise
        vector<vector<bool>> isPalindrome(3, vector<bool>(N));
        int startIdx = 0;
        int maxLen = 0;
        for(int len = 1; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                if(s[i] == s[i + len - 1] && (len <= 2 || isPalindrome[(len - 2) % 3][i + 1])){
                    isPalindrome[len % 3][i] = true;
                }else{
                    isPalindrome[len % 3][i] = false;
                }
                if(len > maxLen && isPalindrome[len % 3][i]){
                    startIdx = i;
                    maxLen = len;
                }
            }
        }
        
        return s.substr(startIdx, maxLen);
    }
};