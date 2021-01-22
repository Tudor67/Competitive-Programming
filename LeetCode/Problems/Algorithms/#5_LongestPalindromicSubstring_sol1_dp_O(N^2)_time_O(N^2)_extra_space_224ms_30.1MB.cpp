class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.length();
        vector<vector<bool>> isPalindrome(N, vector<bool>(N, false));
        int maxPalindromeStartPos = 0;
        int maxPalindromeLength = 1;
        for(int len = 1; len <= N; ++len){
            for(int i = 0, j = i + len - 1; j < N; ++i, ++j){
                if(s[i] == s[j] && (i + 1 >= j - 1 || isPalindrome[i + 1][j - 1])){
                    isPalindrome[i][j] = true;
                    maxPalindromeStartPos = i;
                    maxPalindromeLength = len;
                }
            }
        }
        return s.substr(maxPalindromeStartPos, maxPalindromeLength);
    }
};