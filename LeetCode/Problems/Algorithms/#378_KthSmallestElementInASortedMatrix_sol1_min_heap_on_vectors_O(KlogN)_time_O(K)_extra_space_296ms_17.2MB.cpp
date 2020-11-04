class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        for(int row = 0; row < matrix.size(); ++row){
            minHeap.push({matrix[row][0], row, 0});
        }
        
        for(; k > 1; --k){
            int row = minHeap.top()[1];
            int col = minHeap.top()[2];
            minHeap.pop();
            
            if(col + 1 < matrix[row].size()){
                minHeap.push({matrix[row][col + 1], row, col + 1});
            }
        }
        
        return minHeap.top()[0];
    }
};