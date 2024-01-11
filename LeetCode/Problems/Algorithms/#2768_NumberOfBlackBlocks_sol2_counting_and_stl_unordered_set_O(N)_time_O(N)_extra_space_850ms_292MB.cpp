class Solution {
private:
    struct PairHash{
        size_t operator()(const pair<int, int>& P) const {
            size_t a = P.first;
            size_t b = P.second;
            return (a << 17) | b;
        }
    };

public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        const int ROWS = m;
        const int COLS = n;

        unordered_set<pair<int, int>, PairHash> blackCells;
        unordered_set<pair<int, int>, PairHash> startCells;
        for(const vector<int>& C: coordinates){
            int row = C[0];
            int col = C[1];
            blackCells.insert({row, col});

            for(int startRow = max(0, row - 1); startRow <= min(row, ROWS - 2); ++startRow){
                for(int startCol = max(0, col - 1); startCol <= min(col, COLS - 2); ++startCol){
                    startCells.insert({startRow, startCol});
                }
            }
        }

        vector<long long> f(5);
        for(const pair<int, int>& START_CELL: startCells){
            int startRow = START_CELL.first;
            int startCol = START_CELL.second;

            int blackCellsFreq = 0;
            for(int row = startRow; row <= startRow + 1; ++row){
                for(int col = startCol; col <= startCol + 1; ++col){
                    blackCellsFreq += blackCells.count({row, col});
                }
            }

            f[blackCellsFreq] += 1;
        }

        long long totalBlocks = (long long)(ROWS - 1) * (long long)(COLS - 1);
        long long blocksWithBlackCells = accumulate(f.begin(), f.end(), (long long)0);
        f[0] = totalBlocks - blocksWithBlackCells;

        return f;
    }
};