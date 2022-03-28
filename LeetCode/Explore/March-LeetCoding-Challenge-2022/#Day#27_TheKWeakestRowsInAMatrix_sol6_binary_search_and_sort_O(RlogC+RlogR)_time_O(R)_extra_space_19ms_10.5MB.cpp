class Solution {
private:
    int countSoldiers(vector<int>& v){
        int l = 0;
        int r = v.size();
        while(l != r){
            int mid = (l + r) / 2;
            if(v[mid] == 1){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        
        vector<pair<int, int>> soldiersRow(ROWS);
        for(int row = 0; row < ROWS; ++row){
            soldiersRow[row] = {countSoldiers(mat[row]), row};
        }
        
        sort(soldiersRow.begin(), soldiersRow.end());
        
        vector<int> indices(k);
        for(int i = 0; i < k; ++i){
            indices[i] = soldiersRow[i].second;
        }
        
        return indices;
    }
};