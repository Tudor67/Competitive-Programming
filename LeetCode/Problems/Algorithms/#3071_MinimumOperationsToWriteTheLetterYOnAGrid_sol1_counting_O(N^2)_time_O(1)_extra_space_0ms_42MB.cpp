class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        vector<int> inCount(3);
        for(int row = 0; row < N / 2; ++row){
            inCount[grid[row][row]] += 1;
            inCount[grid[row][N - 1 - row]] += 1;
        }
        
        for(int row = N / 2; row < N; ++row){
            inCount[grid[row][N / 2]] += 1;
        }
        
        vector<int> outCount(3);
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                outCount[grid[row][col]] += 1;
            }
        }
        
        for(int val = 0; val < 3; ++val){
            outCount[val] -= inCount[val];
        }
        
        int minCost = N * N;
        for(int inVal = 0; inVal < 3; ++inVal){
            for(int outVal = 0; outVal < 3; ++outVal){
                if(inVal != outVal){
                    int inCost = inCount[0] + inCount[1] + inCount[2] - inCount[inVal];
                    int outCost = outCount[0] + outCount[1] + outCount[2] - outCount[outVal];
                    minCost = min(minCost, inCost + outCost);
                }
            }
        }
        
        return minCost;
    }
};