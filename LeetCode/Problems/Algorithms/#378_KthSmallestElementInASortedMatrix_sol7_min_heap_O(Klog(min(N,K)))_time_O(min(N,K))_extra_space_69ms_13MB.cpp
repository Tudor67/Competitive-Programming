class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int K) {
        const int N = matrix.size();
        
        using T3 = tuple<int, int, int>;
        priority_queue<T3, vector<T3>, greater<T3>> minHeap;
        for(int row = 0; row < min(N, K); ++row){
            minHeap.emplace(matrix[row][0], row, 0);
        }
        
        for(int i = 1; i <= K - 1; ++i){
            int val, row, col;
            tie(val, row, col) = minHeap.top();
            minHeap.pop();
            
            if(col + 1 < N){
                minHeap.emplace(matrix[row][col + 1], row, col + 1);
            }
        }
        
        return get<0>(minHeap.top());
    }
};