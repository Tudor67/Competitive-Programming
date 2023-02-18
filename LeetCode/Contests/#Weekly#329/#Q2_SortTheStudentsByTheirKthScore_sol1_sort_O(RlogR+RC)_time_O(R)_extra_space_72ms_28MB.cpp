class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        const int ROWS = score.size();
        const int COLS = score[0].size();
        
        vector<int> p(ROWS);
        iota(p.begin(), p.end(), 0);
        
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return score[lhs][k] > score[rhs][k];
             });
        
        vector<vector<int>> res(ROWS, vector<int>(COLS));
        for(int i = 0; i < ROWS; ++i){
            res[i] = score[p[i]];
        }
        
        return res;
    }
};