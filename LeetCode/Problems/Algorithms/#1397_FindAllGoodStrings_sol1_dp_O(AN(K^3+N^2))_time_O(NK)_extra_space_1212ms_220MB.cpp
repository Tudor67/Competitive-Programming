class Solution {
private:
    int lps(const string& A, const string& B){
        const int N = A.length();
        const int M = B.length();
        for(int i = min(N, M); i >= 1; --i){
            if(A.compare(0, i, B, M - i, i) == 0){
                return i;
            }
        }
        return 0;
    }
    
    long long countLessOrEqual(const string& S, const string& EVIL, const long long& MODULO){
        const int N = S.length();
        const int K = EVIL.length();
        
        // dpLess[i][j]: number of good strings of length i which are less than S[0 .. i - 1]
        //               such that EVIL[0 .. j - 1] == S[i - j .. i - 1] is the longest prefix-suffix
        // dpEqual[i][j]: number of good strings of length i which are equal to S[0 .. i - 1]
        //                such that EVIL[0 .. j - 1] == S[i - j .. i - 1] is the longest prefix-suffix
        vector<vector<long long>> dpLess(N + 1, vector<long long>(K + 1));
        vector<vector<long long>> dpEqual(N + 1, vector<long long>(K + 1));
        dpEqual[0][0] = 1;
        
        bool evilInPrefix = false;
        for(int i = 1; i <= N; ++i){
            for(int j = 0; j < K; ++j){
                for(char c = 'a'; c <= 'z'; ++c){
                    dpLess[i][lps(EVIL, EVIL.substr(0, j) + c)] += dpLess[i - 1][j];
                }
            }
            if(!evilInPrefix){
                for(char c = 'a'; c < S[i - 1]; ++c){
                    dpLess[i][lps(EVIL, S.substr(0, i - 1) + c)] += dpEqual[i - 1][lps(EVIL, S.substr(0, i - 1))];
                }
                dpEqual[i][lps(EVIL, S.substr(0, i))] = 1;
                if(lps(EVIL, S.substr(0, i)) == K){
                    evilInPrefix = true;
                }
            }
            for(int j = 0; j < K; ++j){
                dpLess[i][j] %= MODULO;
            }
        }
        
        long long answer = (long long)(S.find(EVIL) == string::npos);
        for(int j = 0; j < K; ++j){
            answer += dpLess[N][j];
            answer %= MODULO;
        }
        
        return answer;
    }
    
public:
    int findGoodStrings(int N, string s1, string s2, string evil) {
        const long long MODULO = 1e9 + 7;
        long long answer = countLessOrEqual(s2, evil, MODULO) -
                           countLessOrEqual(s1, evil, MODULO) +
                           (int)(s1.find(evil) == string::npos);
        answer += MODULO;
        answer %= MODULO;
        return answer;
    }
};