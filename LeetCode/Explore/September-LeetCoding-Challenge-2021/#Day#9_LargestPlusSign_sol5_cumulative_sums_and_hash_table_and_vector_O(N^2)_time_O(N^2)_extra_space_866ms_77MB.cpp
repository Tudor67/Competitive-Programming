class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        unordered_set<int> minesSet;
        for(const vector<int>& P: mines){
            minesSet.insert((P[0] + 1) * (N + 2) + P[1] + 1);
        }
        
        vector<vector<int>> upOnes(N + 2, vector<int>(N + 2));
        vector<vector<int>> downOnes(N + 2, vector<int>(N + 2));
        vector<vector<int>> leftOnes(N + 2, vector<int>(N + 2));
        vector<vector<int>> rightOnes(N + 2, vector<int>(N + 2));
        
        for(int row = 1; row <= N; ++row){
            for(int col = 1; col <= N; ++col){
                if(!minesSet.count(row * (N + 2) + col)){
                    upOnes[row][col] = upOnes[row - 1][col] + 1;
                    leftOnes[row][col] = leftOnes[row][col - 1] + 1;
                }
            }
        }
        
        for(int row = N; row >= 1; --row){
            for(int col = N; col >= 1; --col){
                if(!minesSet.count(row * (N + 2) + col)){
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