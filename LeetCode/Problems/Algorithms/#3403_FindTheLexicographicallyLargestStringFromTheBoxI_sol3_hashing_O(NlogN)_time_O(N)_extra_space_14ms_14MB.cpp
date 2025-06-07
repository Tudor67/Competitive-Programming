class RollingHash{
private:
    const long long BASE;
    const long long MODULO;
    vector<long long> p;
    vector<long long> h;

public:
    RollingHash(const long long BASE, const long long MODULO, const string& S): BASE(BASE), MODULO(MODULO) {
        const int N = S.length();

        p.assign(N, 1);
        for(int i = 1; i < N; ++i){
            p[i] = (p[i - 1] * BASE) % MODULO;
        }

        h.assign(N, 0);
        h[0] = S[0];
        for(int i = 1; i < N; ++i){
            h[i] = ((h[i - 1] * BASE) + S[i]) % MODULO;
        }
    }

    long long getRangeHash(const int L, const int R){
        if(L > R){
            return -1;
        }
        if(L == 0){
            return h[R];
        }
        return (h[R] - h[L - 1] * p[R - (L - 1)] % MODULO + MODULO) % MODULO;
    }
};

class Solution {
public:
    string answerString(string word, int numFriends) {
        const int N = word.length();
        const int MAX_LEN = N - numFriends + 1;
        const int BASE = 131;
        const int MODULO1 = 1'000'000'007;
        const int MODULO2 = 1'000'000'009;

        if(numFriends == 1){
            return word;
        }

        RollingHash hash1(BASE, MODULO1, word);
        RollingHash hash2(BASE, MODULO2, word);

        int resStartIndex = 0;
        for(int i = 0; i < N; ++i){
            int l = 1;
            int r = min(N - i, MAX_LEN);
            while(l != r){
                int mid = (l + r) / 2;
                if(hash1.getRangeHash(i, i + mid - 1) == hash1.getRangeHash(resStartIndex, resStartIndex + mid - 1) &&
                   hash2.getRangeHash(i, i + mid - 1) == hash2.getRangeHash(resStartIndex, resStartIndex + mid - 1)){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }

            int len = r;
            if(i + len - 1 < N && word[i + len - 1] > word[resStartIndex + len - 1]){
                resStartIndex = i;
            }
        }

        return word.substr(resStartIndex, MAX_LEN);
    }
};