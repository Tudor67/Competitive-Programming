class Solution {
public:
    int numOfWays(int n) {
        const unsigned int MODULO = 1'000'000'007;

        unsigned int colors3 = 6;
        unsigned int colors2 = 6;

        for(int row = 2; row <= n; ++row){
            unsigned int prevColors3 = colors3;
            unsigned int prevColors2 = colors2;
            colors3 = (prevColors3 * 2 + prevColors2 * 2) % MODULO;
            colors2 = (prevColors3 * 2 + prevColors2 * 3 % MODULO) % MODULO;
        }

        return (colors3 + colors2) % MODULO;
    }
};