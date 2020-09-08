class Solution {
private:
    bool is_valid(const string& S, const int& K){
        if(S.length() <= K){
            return false;
        }
        for(int i = K; i < S.length(); ++i){
            if(S[i - K] != S[i]){
                return false;
            }
        }
        return true;
    }
    
public:
    bool repeatedSubstringPattern(string s) {
        const int N = s.length();
        for(int i = 1; i * i <= N; ++i){
            if(N % i == 0){
                if(is_valid(s, i) || is_valid(s, N / i)){
                    return true;
                }
            }
        }
        return false;
    }
};