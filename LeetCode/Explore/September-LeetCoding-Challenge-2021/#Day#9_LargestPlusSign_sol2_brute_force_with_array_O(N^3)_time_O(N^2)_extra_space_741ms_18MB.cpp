class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
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
        
        int maxK = 0;
        for(int row = 1; row <= N - maxK; ++row){
            for(int col = 1; col <= N - maxK; ++col){
                if(a[row][col]){
                    int k = 0;
                    bool isValid = true;
                    while(isValid){
                        k += 1;
                        for(const pair<int, int>& DIRECTION: DIRECTIONS){
                            int nextRow = row + k * DIRECTION.first;
                            int nextCol = col + k * DIRECTION.second;
                            if(!a[nextRow][nextCol]){
                                isValid = false;
                            }
                        }
                    }
                    maxK = max(maxK, k);
                }
            }
        }
        
        return maxK;
    }
};