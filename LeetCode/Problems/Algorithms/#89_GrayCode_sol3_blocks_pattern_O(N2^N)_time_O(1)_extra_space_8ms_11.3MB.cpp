class Solution {
public:
    vector<int> grayCode(int n) {
        const int SIZE = 1 << n;
        vector<int> grayCodes(SIZE, 0);
        for(int bit = 0; bit < n; ++bit){
            int blockSize = 1 << (bit + 1);
            for(int i = blockSize / 2; i < SIZE; i += 2 * blockSize){
                for(int j = i; j < min(i + blockSize, SIZE); ++j){
                    grayCodes[j] |= (1 << bit);
                }
            }
        }
        return grayCodes;
    }
};

/*
n = 1     n = 2     n = 3
0           00       000
1           01       001
            11       011
            10       010
                     110
                     111
                     101
                     100
*/