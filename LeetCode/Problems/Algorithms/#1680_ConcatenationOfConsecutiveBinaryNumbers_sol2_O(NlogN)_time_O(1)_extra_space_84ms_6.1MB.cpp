class Solution {
public:
    int concatenatedBinary(int n) {
        const int MODULO = 1e9 + 7;
        int answer = 0;
        for(int i = 1; i <= n; ++i){
            int logI = 1 + int(floor(log2(i)));
            answer = ((1LL << logI) * answer + i) % MODULO;
        }
        return answer;
    }
};