class Solution {    
public:
    string longestPalindrome(string originalS) {
        // Step 1: modify the originalS to s by adding a bogus char ('|') between each char
        string s = "|";
        for(char c: originalS){
            s += string(1, c) + "|";
        }
        
        // Step 2: apply manacher's algorithm on s (with odd length)
        const int N = s.length(); // N: length of s
        vector<int> c(N); // c[i]: number of palindromic substrings with center in s[i]
        int r = -1;       // r: right boundary of the rightmost palindromic substring
        int l = 0;        // l: left boundary of the rightmost palindromic substring
        for(int i = 1; i < N; ++i){
            if(i <= r){
                int iMirror = l + r - i;
                c[i] = min(c[iMirror], r - i);
            }
            while(0 <= i - c[i] && i + c[i] < N && s[i - c[i]] == s[i + c[i]]){
                c[i] += 1;
            }
            c[i] -= 1;
            if(i + c[i] > r){
                r = i + c[i];
                l = i - c[i];
            }
        }
        
        // Step 3: extract the longestPalindromeSubstring using vector c and originalS
        int longestPalindromeStartPos = 0;
        int longestPalindromeLength = 1;
        for(int i = 1; i < N; ++i){
            if(c[i] > longestPalindromeLength){
                longestPalindromeStartPos = i / 2 - c[i] / 2;
                longestPalindromeLength = c[i];
            }
        }
        
        return originalS.substr(longestPalindromeStartPos, longestPalindromeLength);
    }
};