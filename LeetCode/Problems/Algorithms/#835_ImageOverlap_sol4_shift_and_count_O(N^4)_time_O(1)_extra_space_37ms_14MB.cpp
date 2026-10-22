class Solution {
private:
    int computeOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int rowShift, int colShift){
        const int N = img1.size();

        int overlap = 0;
        for(int row1 = 0; row1 < N; ++row1){
            for(int col1 = 0; col1 < N; ++col1){
                int row2 = row1 + rowShift;
                int col2 = col1 + colShift;
                if(0 <= row2 && row2 < N && 0 <= col2 && col2 < N){
                    overlap += (img1[row1][col1] * img2[row2][col2]);
                }
            }
        }

        return overlap;
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int N = img1.size();

        int maxOverlap = 0;
        for(int rowShift = -(N - 1); rowShift <= N - 1; ++rowShift){
            for(int colShift = -(N - 1); colShift <= N - 1; ++colShift){
                maxOverlap = max(maxOverlap, computeOverlap(img1, img2, rowShift, colShift));
            }
        }

        return maxOverlap;
    }
};