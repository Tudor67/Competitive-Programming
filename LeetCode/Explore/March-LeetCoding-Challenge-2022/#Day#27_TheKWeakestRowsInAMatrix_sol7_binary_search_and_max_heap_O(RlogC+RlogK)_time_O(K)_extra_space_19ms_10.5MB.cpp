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
        
        priority_queue<pair<int, int>> maxHeap;
        for(int row = 0; row < ROWS; ++row){
            maxHeap.emplace(countSoldiers(mat[row]), row);
            if((int)maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        vector<int> indices(k);
        while(!maxHeap.empty()){
            indices[(int)maxHeap.size() - 1] = maxHeap.top().second;
            maxHeap.pop();
        }
        
        return indices;
    }
};