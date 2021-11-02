class Solution {
private:
    void mod(long long& a, const long long& MODULO){
        if(a < 0){
            a += MODULO;
        }else if(a >= MODULO){
            a %= MODULO;
        }
    }
    
    void computeHashAndPow(const string& S, const long long& BASE, const long long& MODULO,
                           vector<long long>& hInc, vector<long long>& hDec, vector<long long>& p){
        hInc[0] = S[0];
        hDec[0] = S[0];
        p[0] = 1;
        for(int i = 1; i < (int)S.length(); ++i){
            p[i] = p[i - 1] * BASE;
            mod(p[i], MODULO);
            hInc[i] = hInc[i - 1] + p[i] * S[i];
            mod(hInc[i], MODULO);
            hDec[i] = hDec[i - 1] * BASE + S[i];
            mod(hDec[i], MODULO);
        }
    }
    
    bool isValid(const int& MID_POS, const vector<long long>& MODULOS,
                 vector<vector<long long>>& hInc, vector<vector<long long>>& hDec, vector<vector<long long>>& p){
        const int RADIUS = MID_POS;
        for(int i = 0; i < (int)MODULOS.size(); ++i){
            // normalized lHash for ss[MID_POS - RADIUS .. MID_POS] with increasing BASE powers
            int a = MID_POS - RADIUS;
            int b = MID_POS;
            long long lHash = hInc[i][b];
            if(a - 1 >= 0){
                lHash -= hInc[i][a - 1];
                mod(lHash, MODULOS[i]);
            }
            lHash *= p[i][RADIUS];
            mod(lHash, MODULOS[i]);
            // normalized rHash for ss[MID_POS .. MID_POS + RADIUS] with decreasing BASE powers
            a = MID_POS;
            b = MID_POS + RADIUS;
            long long rHash = hDec[i][b];
            if(a - 1 >= 0){
                long long rem = hDec[i][a - 1] * p[i][b - a + 1];
                mod(rem, MODULOS[i]);
                rHash -= rem;
                mod(rHash, MODULOS[i]);
            }
            rHash *= p[i][a];
            mod(rHash, MODULOS[i]);
            // distinct hashes => ss[MID_POS - RADIUS .. MID_POS] != reverse(ss[MID_POS .. MID_POS + RADIUS])
            if(lHash != rHash){
                return false;
            }
        }
        return true;
    }
    
    int computeMaxLengthOfPalindromePrefix(const string& S){
        const int N = S.length();
        const int L = 2 * N + 1;
        string ss(L, '.');
        for(int i = 0; i < N; ++i){
            ss[2 * i + 1] = S[i];
        }
        
        // rabin karp
        const long long BASE = 131;
        const vector<long long> MODULOS = {(int)(1e9 + 7), (int)(1e9 + 9)};
        
        vector<vector<long long>> hInc(MODULOS.size(), vector<long long>(L));
        vector<vector<long long>> hDec(MODULOS.size(), vector<long long>(L));
        vector<vector<long long>> p(MODULOS.size(), vector<long long>(L));
        
        for(int i = 0; i < (int)MODULOS.size(); ++i){
            computeHashAndPow(ss, BASE, MODULOS[i], hInc[i], hDec[i], p[i]);
        }
        
        int k = 1;
        for(int midPos = 1; midPos + midPos < L; ++midPos){
            if(isValid(midPos, MODULOS, hInc, hDec, p)){
                k = midPos;
            }
        }

        return k;
    }
    
public:
    string shortestPalindrome(string s) {
        if(s.length() <= 1){
            return s;
        }
        
        const int N = s.length();
        const int K = computeMaxLengthOfPalindromePrefix(s);
        
        string answer;
        copy(s.rbegin(), s.rbegin() + N - K, back_inserter(answer));
        copy(s.begin(), s.end(), back_inserter(answer));
        
        return answer;
    }
};