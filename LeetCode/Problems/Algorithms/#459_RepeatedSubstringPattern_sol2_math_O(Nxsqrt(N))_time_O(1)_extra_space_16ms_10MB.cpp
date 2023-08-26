class Solution {
private:
    bool isPossible(const string& S, const int K){
        const int N = S.length();
        if(K <= 0 || N <= K || N % K != 0){
            return false;
        }
        for(int i = K; i < N; ++i){
            if(S[i - K] != S[i]){
                return false;
            }
        }
        return true;
    }

public:
    bool repeatedSubstringPattern(string s) {
        const int N = s.length();
        for(int k = 1; k * k <= N; ++k){
            if(isPossible(s, k) || isPossible(s, N / k)){
                return true;
            }
        }
        return false;
    }
};