class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        for(int row = 0; row < matrix.size(); ++row){
            minHeap.push({matrix[row][0], row, 0});
        }
        
        for(; k > 1; --k){
            int row = get<1>(minHeap.top());
            int col = get<2>(minHeap.top());
            minHeap.pop();
            
            if(col + 1 < matrix[row].size()){
                minHeap.push({matrix[row][col + 1], row, col + 1});
            }
        }
        
        return get<0>(minHeap.top());
    }
};