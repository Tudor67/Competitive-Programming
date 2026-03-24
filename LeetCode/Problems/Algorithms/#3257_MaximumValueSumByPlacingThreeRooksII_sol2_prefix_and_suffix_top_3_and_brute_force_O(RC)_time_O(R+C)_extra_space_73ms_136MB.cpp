class Solution {
private:
    bool containsCol(const vector<pair<int, int>>& VAL_COL_PAIRS, int col){
        for(const auto& [_, currCol]: VAL_COL_PAIRS){
            if(currCol == col){
                return true;
            }
        }
        return false;
    }

    void computePrefTop3(const vector<vector<pair<int, int>>>& V, vector<vector<pair<int, int>>>& prefTop3){
        const int N = V.size();

        prefTop3.clear();
        prefTop3.reserve(N);
        vector<pair<int, int>> best;

        for(int i = 0; i < N; ++i){
            copy(V[i].begin(), V[i].end(), back_inserter(best));
            sort(best.begin(), best.end(), greater<>());

            prefTop3.push_back({});
            for(const auto& [val, col]: best){
                if(!containsCol(prefTop3.back(), col)){
                    prefTop3.back().push_back({val, col});
                }
                if((int)prefTop3.back().size() == 3){
                    break;
                }
            }

            best = prefTop3.back();
        }
    }

public:
    long long maximumValueSum(vector<vector<int>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();

        vector<vector<pair<int, int>>> top3(ROWS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                top3[row].push_back({board[row][col], col});
            }
            partial_sort(top3[row].begin(), top3[row].begin() + 3, top3[row].end(), greater<>());
            top3[row].resize(3);
        }

        vector<vector<pair<int, int>>> prefTop3;
        computePrefTop3(top3, prefTop3);

        vector<vector<pair<int, int>>> suffTop3;
        computePrefTop3(vector<vector<pair<int, int>>>(top3.rbegin(), top3.rend()), suffTop3);
        reverse(suffTop3.begin(), suffTop3.end());

        long long maxSum = LLONG_MIN / 10;
        for(int row = 1; row < ROWS - 1; ++row){
            for(const auto& [val2, col2]: top3[row]){
                for(const auto& [val1, col1]: prefTop3[row - 1]){
                    for(const auto& [val3, col3]: suffTop3[row + 1]){
                        if(col1 != col2 && col1 != col3 && col2 != col3){
                            maxSum = max(maxSum, val1 + (long long)val2 + val3);
                        }
                    }
                }
            }
        }
        
        return maxSum;
    }
};