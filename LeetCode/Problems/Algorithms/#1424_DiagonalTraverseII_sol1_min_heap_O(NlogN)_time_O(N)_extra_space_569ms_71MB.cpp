class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        using TIII = tuple<int, int, int>;
        priority_queue<TIII, vector<TIII>, greater<TIII>> minHeap;
        for(int row = 0; row < (int)nums.size(); ++row){
            for(int col = 0; col < (int)nums[row].size(); ++col){
                int diagIdx = row + col;
                minHeap.emplace(diagIdx, col, row);
            }
        }
        
        const int N = minHeap.size();
        vector<int> diagonalOrder(N);
        for(int i = 0; i < N; ++i){
            int row = get<2>(minHeap.top());
            int col = get<1>(minHeap.top());
            minHeap.pop();
            diagonalOrder[i] = nums[row][col];
        }
        
        return diagonalOrder;
    }
};