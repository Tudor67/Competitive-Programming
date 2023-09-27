class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        vector<vector<int>> freqToRows(COLS + 1);
        for(int row = 0; row < ROWS; ++row){
            int soldiers = upper_bound(mat[row].begin(), mat[row].end(), 1, greater<int>()) - mat[row].begin();
            freqToRows[soldiers].push_back(row);
        }

        vector<int> res;
        res.reserve(k);
        for(int freq = 0; freq <= COLS; ++freq){
            for(int row: freqToRows[freq]){
                if((int)res.size() < k){
                    res.push_back(row);
                }
            }
        }

        return res;
    }
};