class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int a[N + 2][N + 2];
        
        for(int row = 1; row <= N; ++row){
            for(int col = 1; col <= N; ++col){
                a[row][col] = 1;
            }
        }
        
        for(int row = 0; row <= N + 1; ++row){
            a[row][0] = 0;
            a[row][N + 1] = 0;
        }
        
        for(int col = 0; col <= N + 1; ++col){
            a[0][col] = 0;
            a[N + 1][col] = 0;
        }
        
        for(const vector<int>& P: mines){
            a[P[0] + 1][P[1] + 1] = 0;
        }
        
        int upOnes[N + 2][N + 2];
        int downOnes[N + 2][N + 2];
        int leftOnes[N + 2][N + 2];
        int rightOnes[N + 2][N + 2];
        
        for(int row = 0; row <= N + 1; ++row){
            for(int col = 0; col <= N + 1; ++col){
                upOnes[row][col] = 0;
                downOnes[row][col] = 0;
                leftOnes[row][col] = 0;
                rightOnes[row][col] = 0;
            }
        }
        
        for(int row = 1; row <= N; ++row){
            for(int col = 1; col <= N; ++col){
                if(a[row][col]){
                    upOnes[row][col] = upOnes[row - 1][col] + 1;
                    leftOnes[row][col] = leftOnes[row][col - 1] + 1;
                }
            }
        }
        
        for(int row = N; row >= 1; --row){
            for(int col = N; col >= 1; --col){
                if(a[row][col]){
                    downOnes[row][col] = downOnes[row + 1][col] + 1;
                    rightOnes[row][col] = rightOnes[row][col + 1] + 1;
                }
            }
        }
        
        int maxK = 0;
        for(int row = 1; row <= N; ++row){
            for(int col = 1; col <= N; ++col){
                int k = min(min(upOnes[row][col], downOnes[row][col]), min(rightOnes[row][col], leftOnes[row][col]));
                maxK = max(maxK, k);
            }
        }
        
        return maxK;
    }
};