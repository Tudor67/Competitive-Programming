class StringHash{
private:
    const long long BASE = 131;
    const long long MODULO;
    vector<long long> p;
    vector<long long> h;
    
public:
    StringHash(const string& S, const int& MODULO): MODULO(MODULO){
        const int N = S.length();
        
        p.resize(N);
        h.resize(N);
        
        p[0] = 1;
        h[0] = S[0];
        for(int i = 1; i < N; ++i){
            p[i] = (p[i - 1] * BASE) % MODULO;
            h[i] = (h[i - 1] * BASE + S[i]) % MODULO;
        }
    }
    
    int getHash(const int& L, const int& R){
        if(L > R){
            return -1;
        }
        if(L == 0){
            return h[R];
        }
        return (h[R] - (h[L - 1] * p[R - L + 1]) % MODULO + MODULO) % MODULO;
    }
};

class Solution {
private:
    int getStartIdxOfPalindrome(const string& S, const int& TARGET_LENGTH, StringHash& hashObj, StringHash& hashObjRev){
        const int N = S.length();
        if(TARGET_LENGTH == 0){
            return 0;
        }
        for(int i = 0; i + TARGET_LENGTH - 1 < N; ++i){
            if(hashObj.getHash(i, i + TARGET_LENGTH - 1) ==
               hashObjRev.getHash(N - 1 - (i + TARGET_LENGTH - 1), N - 1 - i)){
                return i;
            }
        }
        return -1;
    }
    
public:
    string longestPalindrome(string s) {
        const int N = s.length();
        const int MODULO = 1e9 + 7;
        
        StringHash hashObj(s, MODULO);
        StringHash hashObjRev(string(s.rbegin(), s.rend()), MODULO);
        
        int startIdx = 0;
        int maxLen = 0;
        
        for(int isOddLengthPalindrome: {0, 1}){
            int l = 0;
            int r = N / 2;
            while(l != r){
                int mid = (l + r + 1) / 2;
                int len = 2 * mid + isOddLengthPalindrome;
                if(getStartIdxOfPalindrome(s, len, hashObj, hashObjRev) >= 0){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            int len = 2 * r + isOddLengthPalindrome;
            if(len > maxLen){
                startIdx = getStartIdxOfPalindrome(s, len, hashObj, hashObjRev);
                maxLen = len;
            }
        }
        
        return s.substr(startIdx, maxLen);
    }
};