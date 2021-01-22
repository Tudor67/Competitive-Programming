class Solution {
private:
    void manacherUpdate(const string& S, vector<int>& c, bool isOdd){
        const int N = S.length();
        for(int i = 0, l = 0, r = -1; i < N; ++i){
            int k = (i <= r ? min(c[l + r - i + !isOdd], r - i + 1) : isOdd);
            for(; 0 <= i - k - !isOdd && i + k < N && S[i - k - !isOdd] == S[i + k]; ++k);
            c[i] = k;
            if(i + k - 1 > r){
                r = i + (k - 1);
                l = i - (k - isOdd);
            }
        }
    }
    
public:
    string longestPalindrome(string s) {
        const int N = s.length();
        
        // c1[i] - the number of palindromes with odd length and with center (i)
        vector<int> c1(N);
        manacherUpdate(s, c1, true);
        
        // c2[i] - the number of palindromes with even length and with center (i - 1, i)
        vector<int> c2(N);
        manacherUpdate(s, c2, false);
        
        int maxPalindromeStartPos = 0;
        int maxPalindromeLength = 1;
        for(int i = 0; i < s.length(); ++i){
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