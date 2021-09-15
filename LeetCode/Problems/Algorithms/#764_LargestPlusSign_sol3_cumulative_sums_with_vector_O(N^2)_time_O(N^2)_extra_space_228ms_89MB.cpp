class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> a(N + 2, vector<int>(N + 2, 0));
        for(int row = 1; row <= N; ++row){
            for(int col = 1; col <= N; ++col){
                a[row][col] = 1;
            }
        }
        
        for(const vector<int>& P: mines){
            a[P[0] + 1][P[1] + 1] = 0;
        }
        
        vector<vector<int>> upOnes = a;
        vector<vector<int>> downOnes = a;
        vector<vector<int>> leftOnes = a;
        vector<vector<int>> rightOnes = a;
        
        for(int row = 1; row <= N; ++row){
            for(int col = 1; col <= N; ++col){
                if(a[row][col]){
                    upOnes[row][col] += upOnes[row - 1][col];
                    leftOnes[row][col] += leftOnes[row][col - 1];
                }
            }
        }
        
        for(int row = N; row >= 1; --row){
            for(int col = N; col >= 1; --col){
                if(a[row][col]){
                    downOnes[row][col] += downOnes[row + 1][col];
                    rightOnes[row][col] += rightOnes[row][col + 1];
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