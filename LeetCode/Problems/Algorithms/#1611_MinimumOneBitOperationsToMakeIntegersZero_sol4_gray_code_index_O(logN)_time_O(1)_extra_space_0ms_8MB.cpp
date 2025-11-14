class Solution {
public:
    int minimumOneBitOperations(int g) {
        int idx = 0;
        while(g > 0){
            idx ^= g;
            g >>= 1;
        }
        return idx;
    }
};