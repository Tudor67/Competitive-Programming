class Solution {
public:
    int minimumOneBitOperations(int n) {
        int answer = 0;
        bitset<30> b(n);
        for(int bit = 29; bit >= 0; --bit){
            long long blockSize = 1LL << (bit + 2);
            int blockPos = answer % blockSize + 1;
            int expectedBitVal = (blockSize / 4 + 1 <= blockPos && blockPos <= 3 * blockSize / 4 ? 1 : 0);
            if(b[bit] != expectedBitVal){
                answer |= (1 << bit);
            }
        }
        return answer;
    }
};