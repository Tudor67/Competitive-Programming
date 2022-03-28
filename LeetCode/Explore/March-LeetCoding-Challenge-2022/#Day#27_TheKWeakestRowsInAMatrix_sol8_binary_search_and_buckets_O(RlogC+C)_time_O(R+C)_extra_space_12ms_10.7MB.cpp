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
        
        vector<vector<int>> buckets(COLS + 1);
        for(int row = 0; row < ROWS; ++row){
            buckets[countSoldiers(mat[row])].push_back(row);
        }
        
        vector<int> indices;
        for(int soldiers = 0; soldiers <= COLS; ++soldiers){
            for(int row: buckets[soldiers]){
                if((int)indices.size() < k){
                    indices.push_back(row);
                }
            }
            if((int)indices.size() == k){
                break;
            }
        }
        
        return indices;
    }
};