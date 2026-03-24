class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();

        // Step 1: pick top-3 values per row -> `initialCandidates`
        vector<array<int, 3>> rowValues(COLS);
        vector<array<int, 3>> initialCandidates;
        initialCandidates.reserve(3 * ROWS);

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                rowValues[col] = {board[row][col], row, col};
            }
            partial_sort(rowValues.begin(), rowValues.begin() + 3, rowValues.end(), greater<>());
            copy(rowValues.begin(), rowValues.begin() + 3, back_inserter(initialCandidates));
        }

        sort(initialCandidates.begin(), initialCandidates.end(), greater<>());

        // Step 2: prune to at most 3 values per column -> `filteredCandidates`
        vector<array<int, 3>> filteredCandidates;
        vector<int> colCount(COLS);

        for(const auto& [val, row, col]: initialCandidates){
            colCount[col] += 1;
            if(colCount[col] <= 3){
                filteredCandidates.push_back({val, row, col});
            }
            if((int)filteredCandidates.size() == 11){
                break;
            }
        }

        // Step 3: keep top-11 values globally -> brute force all triples for valid distinct rows and columns
        //         why 11? the worst case scenario
        //             * 1st rook blocks top-5 values (1 val + 2 vals on the same row + 2 vals on the same col)
        //             * 2nd rook blocks the next top-5 values (1 val + 2 vals on the same row + 2 vals on the same col)
        //             * 3rd rook picks the 11th largest value
        long long maxSum = LLONG_MIN / 10;
        for(int i = 0; i < (int)filteredCandidates.size(); ++i){
            for(int j = i + 1; j < (int)filteredCandidates.size(); ++j){
                for(int k = j + 1; k < (int)filteredCandidates.size(); ++k){
                    const auto& [val1, row1, col1] = filteredCandidates[i];
                    const auto& [val2, row2, col2] = filteredCandidates[j];
                    const auto& [val3, row3, col3] = filteredCandidates[k];
                    if(row1 != row2 && row1 != row3 && row2 != row3 &&
                       col1 != col2 && col1 != col3 && col2 != col3){
                        maxSum = max(maxSum, val1 + (long long)val2 + val3);
                        break;
                    }
                }
            }
        }

        return maxSum;
    }
};