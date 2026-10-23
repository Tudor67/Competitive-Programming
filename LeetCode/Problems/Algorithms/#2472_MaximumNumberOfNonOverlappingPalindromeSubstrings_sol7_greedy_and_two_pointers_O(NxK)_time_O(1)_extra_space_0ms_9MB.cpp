class Solution {
private:
    bool isPalindrome(const string& S, int l, int r){
        while(l <= r && S[l] == S[r]){
            l += 1;
            r -= 1;
        }
        return (l > r);
    }

public:
    int maxPalindromes(string s, int k) {
        const int N = s.length();

        int res = 0;
        int maxValidIndex = N - 1;

        for(int i = N - k; i >= 0; --i){
            if((i + k - 1 <= maxValidIndex && isPalindrome(s, i, i + k - 1)) ||
               (i + k <= maxValidIndex && isPalindrome(s, i, i + k))){
                res += 1;
                maxValidIndex = i - 1;
            }
        }

        return res;
    }
};