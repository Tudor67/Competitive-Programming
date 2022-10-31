class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int N = img1.size();
        
        int maxOverlap = 0;
        for(int rowShift = -(N - 1); rowShift <= N - 1; ++rowShift){
            for(int colShift = -(N - 1); colShift <= N - 1; ++colShift){
                int overlap = 0;
                for(int row = 0; row < N; ++row){
                    for(int col = 0; col < N; ++col){
                        if(0 <= row + rowShift && row + rowShift < N &&
                           0 <= col + colShift && col + colShift < N){
                            overlap += img1[row + rowShift][col + colShift] * img2[row][col];
                        }
                    }
                }
                maxOverlap = max(maxOverlap, overlap);
            }
        }
        
        return maxOverlap;
    }
};