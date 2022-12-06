class Solution {
private:
    void manacher(const string& S, vector<int>& maxRadius){
        const int N = S.length();

        // Manacher's algorithm
        string ss(2 * N + 1, '.');
        for(int i = 1; i < 2 * N + 1; i += 2){
            ss[i] = S[i / 2];
        }
        
        // maxRadius[i]: max x such that ss[i - x .. i + x] is palindrome
        maxRadius.assign(2 * N + 1, 0);
        int a = 0;
        int b = 0;
        for(int i = 0; i < 2 * N + 1; ++i){
            if(i <= b){
                maxRadius[i] = min(maxRadius[a + (b - i)], b - i);
            }
            while(0 <= i - maxRadius[i] - 1 && i + maxRadius[i] + 1 < 2 * N + 1 &&
                  ss[i - maxRadius[i] - 1] == ss[i + maxRadius[i] + 1]){
                maxRadius[i] += 1;
            }
            if(i + maxRadius[i] >= b){
                a = i - maxRadius[i];
                b = i + maxRadius[i];
            }
        }
    }

    int getVal(vector<int>& dp, int i){
        if(i < 0 || i >= (int)dp.size()){
            return 0;
        }
        return dp[i];
    }

    bool isPalindrome(int l, int r, vector<int>& maxRadius){
        if(l < 0 || l > r){
            return false;
        }
        int len = r - l + 1;
        int midIndex = (2 * r + 1 + 2 * l + 1) / 2;
        return (maxRadius[midIndex] >= len);
    }
    
public:
    int maxPalindromes(string s, int k) {
        const int N = s.length();
        
        // Manacher's algorithm
        vector<int> maxRadius;
        manacher(s, maxRadius);
        
        // dp[i]: max number of non-overlapping palindromes (of length >= k) in s[0 .. i]
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            dp[i] = getVal(dp, i - 1);
            if(isPalindrome(i - k + 1, i, maxRadius)){
                dp[i] = max(dp[i], getVal(dp, i - k) + 1);
            }
            if(isPalindrome(i - k, i, maxRadius)){
                dp[i] = max(dp[i], getVal(dp, i - k - 1) + 1);
            }
        }
        
        return dp[N - 1];
    }
};