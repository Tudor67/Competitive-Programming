class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        const int ROWS = m;
        const int COLS = n;

        map<pair<int, int>, int> submatrixToBlackCellsFreq;
        for(const vector<int>& C: coordinates){
            int row = C[0];
            int col = C[1];

            for(int startRow = max(0, row - 1); startRow <= min(row, ROWS - 2); ++startRow){
                for(int startCol = max(0, col - 1); startCol <= min(col, COLS - 2); ++startCol){
                    submatrixToBlackCellsFreq[{startRow, startCol}] += 1;
                }
            }
        }

        vector<long long> f(5);
        for(const pair<const pair<int, int>, int>& T: submatrixToBlackCellsFreq){
            int blackCellsFreq = T.second;
            f[blackCellsFreq] += 1;
        }

        long long totalBlocks = (long long)(ROWS - 1) * (long long)(COLS - 1);
        long long blocksWithBlackCells = accumulate(f.begin(), f.end(), (long long)0);
        f[0] = totalBlocks - blocksWithBlackCells;

        return f;
    }
};