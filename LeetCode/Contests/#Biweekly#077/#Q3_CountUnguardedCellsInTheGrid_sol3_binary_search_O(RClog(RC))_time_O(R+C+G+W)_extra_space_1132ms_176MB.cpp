class Solution {
public:
    int countUnguarded(int ROWS, int COLS, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        const int GUARD = 1;
        const int WALL = 2;
        
        vector<vector<pair<int, int>>> valuesAtRow(ROWS);
        vector<vector<pair<int, int>>> valuesAtCol(COLS);
        
        for(const vector<int>& POS: guards){
            int row = POS[0];
            int col = POS[1];
            valuesAtRow[row].emplace_back(col, GUARD);
            valuesAtCol[col].emplace_back(row, GUARD);
        }
        
        for(const vector<int>& POS: walls){
            int row = POS[0];
            int col = POS[1];
            valuesAtRow[row].emplace_back(col, WALL);
            valuesAtCol[col].emplace_back(row, WALL);
        }
        
        for(int row = 0; row < ROWS; ++row){
            sort(valuesAtRow[row].begin(), valuesAtRow[row].end());
        }
        
        for(int col = 0; col < COLS; ++col){
            sort(valuesAtCol[col].begin(), valuesAtCol[col].end());
        }
        
        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                auto it1 = lower_bound(valuesAtRow[row].begin(), valuesAtRow[row].end(), pair<int, int>{col, -1});
                if((it1 != valuesAtRow[row].end() && it1->first == col) ||
                   (it1 != valuesAtRow[row].begin() && prev(it1)->second == GUARD) ||
                   (it1 != valuesAtRow[row].end() && it1->second == GUARD)){
                    continue;
                }
                
                auto it2 = lower_bound(valuesAtCol[col].begin(), valuesAtCol[col].end(), pair<int, int>{row, -1});
                if((it2 != valuesAtCol[col].end() && it2->first == row) ||
                   (it2 != valuesAtCol[col].begin() && prev(it2)->second == GUARD) ||
                   (it2 != valuesAtCol[col].end() && it2->second == GUARD)){
                    continue;
                }
                
                res += 1;
            }
        }
        
        return res;
    }
};