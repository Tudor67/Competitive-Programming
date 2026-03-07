class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int N = grid.size();

        vector<int> suffZeros(N);
        for(int row = 0; row < N; ++row){
            for(int col = N - 1; col >= 0 && grid[row][col] == 0; --col){
                suffZeros[row] += 1;
            }
        }

        int totalOps = 0;
        for(int i = 0; i < N; ++i){
            int minSuffZeros = N - 1 - i;
            for(int j = i; j < N; ++j){
                if(suffZeros[j] >= minSuffZeros){
                    totalOps += (j - i);
                    int temp = suffZeros[j];
                    copy_backward(suffZeros.begin() + i, suffZeros.begin() + j, suffZeros.begin() + j + 1);
                    suffZeros[i] = temp;
                    break;
                }
            }
            
            if(suffZeros[i] < minSuffZeros){
                return -1;
            }
        }

        return totalOps;
    }
};