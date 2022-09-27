class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        const int N = blocks.length();
        
        int minOps = k;
        int white = 0;
        for(int i = 0; i < N; ++i){
            white += (blocks[i] == 'W');
            if(i >= k){
                white -= (blocks[i - k] == 'W');
            }
            if(i >= k - 1){
                minOps = min(minOps, white);
            }
        }
        
        return minOps;
    }
};