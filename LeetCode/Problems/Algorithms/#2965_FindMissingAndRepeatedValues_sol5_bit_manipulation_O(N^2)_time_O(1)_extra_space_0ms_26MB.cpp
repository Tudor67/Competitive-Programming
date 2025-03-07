class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int N = grid.size();

        // Step 1: targetXOR = 1 ^ 2 ^ ... ^ (N * N)
        //         currXOR = grid[0][0] ^ grid[0][1] ^ ... ^ grid[N - 1][N - 1]
        //         duplicateMissingXOR = (duplicate ^ missing) = (targetXOR ^ currXOR)
        int targetXOR = 0;
        for(int num = 1; num <= N * N; ++num){
            targetXOR ^= num;
        }

        int currXOR = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                currXOR ^= grid[row][col];
            }
        }

        int duplicateMissingXOR = targetXOR ^ currXOR;

        // Step 2: we know duplicateMissingXOR and we need to split these numbers using xor properties
        //         xor value of two bits is 1 => that bit is set in duplicate and unset in missing
        //                                            or
        //                                       that bit is set in missing and unset in duplicate
        //         pick any bit that is set to 1 and use that bit to split duplicate and missing numbers 
        int splitMask = duplicateMissingXOR - (duplicateMissingXOR & (duplicateMissingXOR - 1));

        int x = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] & splitMask){
                    x ^= grid[row][col];
                }
            }
        }

        for(int num = 1; num <= N * N; ++num){
            if(num & splitMask){
                x ^= num;
            }
        }

        // Step 3: check if the group with the split bit set to 1 belongs to the duplicate number
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] == x){
                    return {x, x ^ duplicateMissingXOR};
                }
            }
        }

        return {x ^ duplicateMissingXOR, x};
    }
};