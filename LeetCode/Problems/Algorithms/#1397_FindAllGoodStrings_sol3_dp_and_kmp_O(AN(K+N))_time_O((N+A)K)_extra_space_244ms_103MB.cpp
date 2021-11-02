class Solution {
private:
    int lps(const string& PS){
        const int L = PS.length();
        static vector<int> p;
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
        return p.back();
    }
    
    long long countLessOrEqual(const string& S, const string& EVIL, const long long& MODULO){
        const int N = S.length();
        const int K = EVIL.length();
        const int A = 26;
        
        // lpsEC[j][cID]: length of longest prefix-suffix of EVIL + "$" + EVIL[0 .. j - 1] + char('a' + cID)
        //                (i.e., max length of EVIL prefix which is a suffix of EVIL[0 .. j - 1] + char('a' + cID))
        vector<vector<int>> lpsEC(K, vector<int>(A));
        vector<int> p(K);
        for(int i = 1; i < K; ++i){
            int k = p[i - 1];
            while(k > 0 && EVIL[k] != EVIL[i]){
                k = p[k - 1];
            }
            if(EVIL[k] == EVIL[i]){
                k += 1;
            }
            p[i] = k;
        }
        
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
                    dpLess[i][lps(EVIL + "$" + S.substr(0, i - 1) + c)] += dpEqual[i - 1][lps(EVIL + "$" + S.substr(0, i - 1))];
                }
                dpEqual[i][lps(EVIL + "$" + S.substr(0, i))] = 1;
                if(lps(EVIL + "$" + S.substr(0, i)) == K){
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