class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<int> colXOR(COLS, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int row = 0; row < ROWS; ++row){
            int prefXOR = 0;
            for(int col = 0; col < COLS; ++col){
                colXOR[col] ^= matrix[row][col];
                prefXOR ^= colXOR[col];
                minHeap.push(prefXOR);
                if((int)minHeap.size() == k + 1){
                    minHeap.pop();
                }
            }
        }
        
        return minHeap.top();
    }
};