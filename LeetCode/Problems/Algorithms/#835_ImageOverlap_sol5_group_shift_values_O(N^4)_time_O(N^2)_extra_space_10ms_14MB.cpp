class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int N = img1.size();
        const int OFFSET = N - 1;
        const int SIZE = 2 * N - 1;

        vector<pair<int, int>> coords1;
        for(int row1 = 0; row1 < N; ++row1){
            for(int col1 = 0; col1 < N; ++col1){
                if(img1[row1][col1] == 1){
                    coords1.push_back({row1, col1});
                }
            }
        }

        int maxOverlap = 0;
        vector<vector<int>> count(SIZE, vector<int>(SIZE));
        for(int row2 = 0; row2 < N; ++row2){
            for(int col2 = 0; col2 < N; ++col2){
                if(img2[row2][col2] == 1){
                    for(const auto& [row1, col1]: coords1){
                        int rowDiff = row2 - row1 + OFFSET;
                        int colDiff = col2 - col1 + OFFSET;
                        count[rowDiff][colDiff] += 1;
                        maxOverlap = max(maxOverlap, count[rowDiff][colDiff]);
                    }
                }
            }
        }

        return maxOverlap;
    }
};