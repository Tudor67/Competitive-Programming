class Solution {
public:
    int longestDecomposition(string text) {
        const int N = text.length();
        const long long BASE = 131;
        const long long MODULO = 1e9 + 7;
        
        int k = 0;
        int l = 0;
        int r = N - 1;
        int lastValidIdx = -1;
        long long lHash = 0;
        long long rHash = 0;
        long long rPow = 1;
        while(l < r){
            lHash = (lHash * BASE + text[l] - 'a' + 1) % MODULO;
            rHash = (rHash + rPow * (text[r] - 'a' + 1)) % MODULO;
            rPow = (rPow * BASE) % MODULO;
            if(lHash == rHash){
                k += 2;
                lHash = 0;
                rHash = 0;
                rPow = 1;
                lastValidIdx = l;
            }
            l += 1;
            r -= 1;
        }
        
        if(lastValidIdx != (N - 1) / 2){
            k += 1;
        }
        
        return k;
    }
};