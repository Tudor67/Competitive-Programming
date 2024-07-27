class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int N = grid.size();

        int abXOR = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                abXOR ^= grid[row][col];
                abXOR ^= (row * N + col + 1);
            }
        }

        int splitMask = abXOR - (abXOR & (abXOR - 1));

        int a = 0;
        int b = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] & splitMask){
                    a ^= grid[row][col];
                }else{
                    b ^= grid[row][col];
                }
                
                int index = row * N + col + 1;
                if(index & splitMask){
                    a ^= index;
                }else{
                    b ^= index;
                }
            }
        }

        int aFreq = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] == a){
                    aFreq += 1;
                }
            }
        }

        if(aFreq == 0){
            swap(a, b);
        }

        return {a, b};
    }
};