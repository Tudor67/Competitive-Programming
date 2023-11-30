class Solution {
public:
    int minimumOneBitOperations(int n) {
        int idx = 0;
        while(n > 0){
            idx ^= n;
            n >>= 1;
        }
        return idx;
    }
};