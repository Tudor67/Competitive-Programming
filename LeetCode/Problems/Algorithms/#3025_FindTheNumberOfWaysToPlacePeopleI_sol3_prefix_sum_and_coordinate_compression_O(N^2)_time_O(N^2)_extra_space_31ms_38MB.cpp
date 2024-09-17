class Solution {
private:
    int compress(int val, vector<int>& v){
        return lower_bound(v.begin(), v.end(), val) - v.begin();
    }

public:
    int numberOfPairs(vector<vector<int>>& points) {
        const int N = points.size();

        vector<int> vx;
        vector<int> vy;
        for(const vector<int>& POINT: points){
            int x = POINT[0];
            int y = POINT[1];
            vx.push_back(x);
            vy.push_back(y);
        }

        sort(vx.begin(), vx.end());
        vx.resize(unique(vx.begin(), vx.end()) - vx.begin());

        sort(vy.begin(), vy.end());
        vy.resize(unique(vy.begin(), vy.end()) - vy.begin());

        const int ROWS = vy.size();
        const int COLS = vx.size();
        vector<vector<int>> grid(ROWS, vector<int>(COLS));
        vector<pair<int, int>> compressedPoints(N);
        for(int i = 0; i < N; ++i){
            int x = points[i][0];
            int y = points[i][1];
            compressedPoints[i] = {compress(x, vx), ROWS - 1 - compress(y, vy)};
            grid[compressedPoints[i].second][compressedPoints[i].first] = 1;
        }
        
        vector<vector<int>> prefSum = grid;
        for(int row = 1; row < ROWS; ++row){
            prefSum[row][0] += prefSum[row - 1][0];
        }

        for(int col = 1; col < COLS; ++col){
            prefSum[0][col] += prefSum[0][col - 1];
        }

        for(int row = 1; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                prefSum[row][col] += prefSum[row - 1][col] + prefSum[row][col - 1] - prefSum[row - 1][col - 1];
            }
        }

        int validPairs = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                int row1 = compressedPoints[i].second;
                int col1 = compressedPoints[i].first;
                int row2 = compressedPoints[j].second;
                int col2 = compressedPoints[j].first;
                if(row1 <= row2 && col1 <= col2){
                    int sum = prefSum[row2][col2];
                    if(row1 - 1 >= 0){
                        sum -= prefSum[row1 - 1][col2];
                    }
                    if(col1 - 1 >= 0){
                        sum -= prefSum[row2][col1 - 1];
                    }
                    if(row1 - 1 >= 0 && col1 - 1 >= 0){
                        sum += prefSum[row1 - 1][col1 - 1];
                    }
                    if(sum == 2){
                        validPairs += 1;
                    }
                }
            }
        }

        return validPairs;
    }
};