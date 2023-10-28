class Solution {
public:
    int countVowelPermutation(int n) {
        const long long MODULO = 1e9 + 7;
        
        long long a = 1;
        long long e = 1;
        long long i = 1;
        long long o = 1;
        long long u = 1;
        for(int len = 2; len <= n; ++len){
            long long nextA = (e + i + u) % MODULO;
            long long nextE = (a + i) % MODULO;
            long long nextI = (e + o) % MODULO;
            long long nextO = i;
            long long nextU = (i + o) % MODULO;
            a = nextA;
            e = nextE;
            i = nextI;
            o = nextO;
            u = nextU;
        }

        return (a + e + i + o + u) % MODULO;
    }
};