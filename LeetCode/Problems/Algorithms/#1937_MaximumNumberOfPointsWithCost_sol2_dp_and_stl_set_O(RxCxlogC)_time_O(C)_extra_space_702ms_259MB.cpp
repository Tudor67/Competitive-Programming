class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int ROWS = points.size();
        const int COLS = points[0].size();

        // At (row)th iteration:
        //    maxPoints[row % 2][col]: max points at cell (row, col)
        //                             when we start from the first row
        vector<vector<long long>> maxPoints(2, vector<long long>(COLS));
        for(int col = 0; col < COLS; ++col){
            maxPoints[0][col] = points[0][col];
        }

        for(int row = 1; row < ROWS; ++row){
            set<pair<long long, int>> ls;
            set<pair<long long, int>> rs;
            for(int col = 0; col < COLS; ++col){
                rs.insert({maxPoints[(row - 1) % 2][col] - col, col});
            }

            for(int col = 0; col < COLS; ++col){
                ls.insert({maxPoints[(row - 1) % 2][col] + col, col});
                maxPoints[row % 2][col] = points[row][col] +
                                          max(ls.rbegin()->first - col,
                                              rs.rbegin()->first + col);
                rs.erase({maxPoints[(row - 1) % 2][col] - col, col});
            }
        }

        return *max_element(maxPoints[(ROWS - 1) % 2].begin(), maxPoints[(ROWS - 1) % 2].end());
    }
};