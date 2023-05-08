class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                               {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    bool isInside(int row, int col, const int& N){
        return (0 <= row && row < N && 0 <= col && col < N);
    }

public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        const int N = grid.size();

        if(grid[0][0] != 0){
            return false;
        }

        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] < N * N - 1){
                    bool isValid = false;
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int nextRow = row + DIRECTION.first;
                        int nextCol = col + DIRECTION.second;
                        if(isInside(nextRow, nextCol, N) && grid[row][col] + 1 == grid[nextRow][nextCol]){
                            isValid = true;
                            break;
                        }
                    }
                    if(!isValid){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};