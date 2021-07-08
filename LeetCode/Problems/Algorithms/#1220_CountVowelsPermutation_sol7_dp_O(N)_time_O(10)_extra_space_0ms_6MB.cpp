class Solution {
public:
    int countVowelPermutation(int N) {
        const unsigned int MODULO = 1e9 + 7;
        
        unsigned int a = 1;
        unsigned int e = 1;
        unsigned int i = 1;
        unsigned int o = 1;
        unsigned int u = 1;
        
        for(int step = 2; step <= N; ++step){
            unsigned int aPrev = a;
            unsigned int ePrev = e;
            unsigned int iPrev = i;
            unsigned int oPrev = o;
            unsigned int uPrev = u;
            a = (ePrev + iPrev + uPrev) % MODULO;
            e = (aPrev + iPrev) % MODULO;
            i = (ePrev + oPrev) % MODULO;
            o = iPrev;
            u = (oPrev + iPrev) % MODULO;
        }
        
        return ((a + e) % MODULO + (i + o + u) % MODULO) % MODULO;
    }
};