class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.length();

        int maxLen = 0;
        int maxLenStartIndex = 0;
        vector<vector<bool>> isPalindrome(N, vector<bool>(N, false));
        
        for(int len = 1; len <= N; ++len){
            for(int l = 0; l + len - 1 < N; ++l){
                int r = l + len - 1;
                if(s[l] == s[r]){
                    if(len <= 2 || isPalindrome[l + 1][r - 1]){
                        isPalindrome[l][r] = true;
                    }
                }

                if(isPalindrome[l][r] && maxLen < len){
                    maxLen = len;
                    maxLenStartIndex = l;
                }
            }
        }

        return s.substr(maxLenStartIndex, maxLen);
    }
};