class Solution {
private:
    void computeLPS(const string& PS, vector<int>& p){
        const int L = PS.length();
        p.assign(L, 0);
        for(int i = 1; i < L; ++i){
            int k = p[i - 1];
            while(k > 0 && PS[k] != PS[i]){
                k = p[k - 1];
            }
            if(PS[k] == PS[i]){
                p[i] = k + 1;
            }
        }
    }
    
    long long countLessOrEqual(const string& S, const string& EVIL, const long long& MODULO){
        const int N = S.length();
        const int K = EVIL.length();
        const int A = 26;
        
        // lpsEC[j][cID]: length of longest prefix-suffix of EVIL + "$" + EVIL[0 .. j - 1] + char('a' + cID)
        //                (i.e., max length of EVIL prefix which is a suffix of EVIL[0 .. j - 1] + char('a' + cID))
        vector<vector<int>> lpsEC(K, vector<int>(A));
        vector<int> p(K);
        computeLPS(EVIL, p);
        
        for(int j = 0; j < K; ++j){
            for(char c = 'a'; c <= 'z'; ++c){
                int k = j;
                while(k > 0 && EVIL[k] != c){
                    k = p[k - 1];
                }
                if(EVIL[k] == c){
                    k += 1;
                }
                lpsEC[j][c - 'a'] = k;
            }
        }
        
        // lpsS[j]: length of longest prefix-suffix of EVIL + "$" + S[0 .. j - 1]
        //          (i.e., max length of EVIL prefix which is a suffix of S[0 .. j - 1])
        computeLPS(EVIL + "$" + S, p);
        vector<int> lpsS(p.begin() + K, p.end());
        
        // lpsSC[j][cID]: length of longest prefix-suffix of EVIL + "$" + S[0 .. j - 1] + char('a' + cID)
        //                (i.e., max length of EVIL prefix which is a suffix of S[0 .. j - 1] + char('a' + cID))
        vector<vector<int>> lpsSC(N + 1, vector<int>(A));
        for(int j = 0; j <= N; ++j){
            for(char c = 'a'; c <= 'z'; ++c){
                int k = lpsS[j];
                while(k > 0 && EVIL[k] != c){
                    k = p[k - 1];
                }
                if(EVIL[k] == c){
                    k += 1;
                }
                lpsSC[j][c - 'a'] = k;
            }
        }
        
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
                    dpLess[i][lpsEC[j][c - 'a']] += dpLess[i - 1][j];
                }
            }
            if(!evilInPrefix){
                for(char c = 'a'; c < S[i - 1]; ++c){
                    dpLess[i][lpsSC[i - 1][c - 'a']] += dpEqual[i - 1][lpsS[i - 1]];
                }
                dpEqual[i][lpsS[i]] = 1;
                if(lpsS[i] == K){
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