class Solution {
public:
    string longestPalindrome(string s) {
        int maxPalindromeStartPos = 0;
        int maxPalindromeLength = 1;
        for(int mid = 0; mid < s.length(); ++mid){
            for(int shift: {0, 1}){
                for(int i = mid, j = mid + shift; i >= 0 && j < s.length() && s[i] == s[j]; --i, ++j){
                    if(j - i + 1 > maxPalindromeLength){
                        maxPalindromeStartPos = i;
                        maxPalindromeLength = j - i + 1;
                    }
                }
            }
        }
        return s.substr(maxPalindromeStartPos, maxPalindromeLength);
    }
};