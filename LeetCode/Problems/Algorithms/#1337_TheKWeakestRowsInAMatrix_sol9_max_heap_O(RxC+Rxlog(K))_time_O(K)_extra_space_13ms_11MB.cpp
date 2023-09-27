class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        priority_queue<pair<int, int>> maxHeap;
        for(int row = 0; row < ROWS; ++row){
            int soldiers = 0;
            for(int col = 0; col < COLS && mat[row][col] == 1; ++col){
                soldiers += 1;
            }
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