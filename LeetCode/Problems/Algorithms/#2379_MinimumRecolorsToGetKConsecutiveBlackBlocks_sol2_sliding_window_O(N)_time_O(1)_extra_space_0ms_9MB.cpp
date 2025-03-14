class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        const int N = blocks.size();

        int minOps = k;
        int whiteBlocks = 0;
        for(int i = 0; i < N; ++i){
            whiteBlocks += (int)(blocks[i] == 'W');
            if(i >= k){
                whiteBlocks -= (int)(blocks[i - k] == 'W');
            }
            if(i >= k - 1){
                minOps = min(minOps, whiteBlocks);
            }
        }

        return minOps;
    }
};