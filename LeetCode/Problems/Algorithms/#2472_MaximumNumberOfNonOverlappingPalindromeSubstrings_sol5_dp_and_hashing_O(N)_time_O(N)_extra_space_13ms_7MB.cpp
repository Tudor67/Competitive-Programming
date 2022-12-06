class RollingHash{
private:
    const long long BASE;
    const long long MODULO;
    vector<long long> h;
    vector<long long> p;

public:
    RollingHash(const string& S, const long long& BASE, const long long& MODULO): BASE(BASE), MODULO(MODULO){
        const int N = S.length();
        h.resize(N);
        p.resize(N);
        h[0] = S[0];
        p[0] = 1;
        for(int i = 1; i < N; ++i){
            h[i] = (h[i - 1] * BASE + S[i]) % MODULO;
            p[i] = (p[i - 1] * BASE) % MODULO;
        }
    }

    long long getRangeHash(const int& L, const int& R){
        if(L == 0){
            return h[R];
        }
        return (h[R] - ((h[L - 1] * p[R - L + 1]) % MODULO) + MODULO) % MODULO;
    }
};

class Solution {
private:
    int getVal(vector<int>& dp, int i){
        if(i < 0 || i >= (int)dp.size()){
            return 0;
        }
        return dp[i];
    }
    
public:
    int maxPalindromes(string s, int k) {
        const int N = s.length();
        const long long BASE = 131;
        const long long MODULO = 1e9 + 7;

        // hashing is used to check if a substring is a palindrome
        RollingHash sHash(s, BASE, MODULO);
        RollingHash sRevHash(string(s.rbegin(), s.rend()), BASE, MODULO);

        // dp[i]: max number of non-overlapping palindromes (of length >= k) in s[0 .. i]
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            dp[i] = getVal(dp, i - 1);
            if(0 <= i - k + 1){
                if(sHash.getRangeHash(i - k + 1, i) == sRevHash.getRangeHash((N - 1) - i, (N - 1) - (i - k + 1))){
                    dp[i] = max(dp[i], getVal(dp, i - k) + 1);
                }
            }
            if(0 <= i - k){
                if(sHash.getRangeHash(i - k, i) == sRevHash.getRangeHash((N - 1) - i, (N - 1) - (i - k))){
                    dp[i] = max(dp[i], getVal(dp, i - k - 1) + 1);
                }
            }
        }
        
        return dp[N - 1];
    }
};