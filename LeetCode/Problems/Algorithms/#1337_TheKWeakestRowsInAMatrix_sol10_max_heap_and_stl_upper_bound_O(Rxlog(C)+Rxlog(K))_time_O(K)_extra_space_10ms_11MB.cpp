class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        priority_queue<pair<int, int>> maxHeap;
        for(int row = 0; row < ROWS; ++row){
            int soldiers = upper_bound(mat[row].begin(), mat[row].end(), 1, greater<int>()) - mat[row].begin();
            maxHeap.push({soldiers, row});
            if((int)maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        vector<int> res(k);
        for(int i = k - 1; i >= 0; --i){
            res[i] = maxHeap.top().second;
            maxHeap.pop();
        }

        return res;
    }
};