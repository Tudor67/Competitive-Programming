class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.length();
        
        // c1[i] - the number of palindromes with odd length and with center (i)
        vector<int> c1(N);
        for(int i = 0, l = 0, r = -1; i < N; ++i){
            int k = (i <= r ? min(c1[l + r - i], r - i + 1) : 1);
            for(; 0 <= i - k && i + k < N && s[i - k] == s[i + k]; ++k);
            c1[i] = k;
            if(i + k - 1 > r){
                r = i + (k - 1);
                l = i - (k - 1);
            }
        }
        
        // c2[i] - the number of palindromes with even length and with center (i - 1, i)
        vector<int> c2(N);
        for(int i = 0, l = 0, r = -1; i < N; ++i){
            int k = (i <= r ? min(c2[l + r - i + 1], r - i + 1) : 0);
            for(; 0 <= i - 1 - k && i + k < N && s[i - 1 - k] == s[i + k]; ++k);
            c2[i] = k;
            if(i + k - 1 > r){
                r = i + k - 1;
                l = i - k;
            }
        }
        
        int maxPalindromeStartPos = 0;
        int maxPalindromeLength = 1;
        for(int i = 0; i < N; ++i){
            if(2 * c1[i] - 1 > maxPalindromeLength){
                maxPalindromeLength = 2 * c1[i] - 1;
                maxPalindromeStartPos = i - c1[i] + 1;
            }
            if(2 * c2[i] > maxPalindromeLength){
                maxPalindromeLength = 2 * c2[i];
                maxPalindromeStartPos = i - c2[i];
            }
        }
        
        return s.substr(maxPalindromeStartPos, maxPalindromeLength);
    }
};