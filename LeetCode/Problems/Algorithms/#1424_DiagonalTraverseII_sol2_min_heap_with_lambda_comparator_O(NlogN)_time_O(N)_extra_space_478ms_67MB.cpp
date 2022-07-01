class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        using PII = pair<int, int>;
        auto decDiagColComp = [](const PII& LHS, const PII& RHS){
            int lhsDiag = LHS.first + LHS.second;
            int lhsCol = LHS.second;
            int rhsDiag = RHS.first + RHS.second;
            int rhsCol = RHS.second;
            return (pair<int, int>{lhsDiag, lhsCol} > pair<int, int>{rhsDiag, rhsCol});
        };
        
        priority_queue<PII, vector<PII>, decltype(decDiagColComp)> minHeap(decDiagColComp);
        for(int row = 0; row < (int)nums.size(); ++row){
            for(int col = 0; col < (int)nums[row].size(); ++col){
                minHeap.emplace(row, col);
            }
        }
        
        const int N = minHeap.size();
        vector<int> diagonalOrder(N);
        for(int i = 0; i < N; ++i){
            int row = minHeap.top().first;
            int col = minHeap.top().second;
            minHeap.pop();
            diagonalOrder[i] = nums[row][col];
        }
        
        return diagonalOrder;
    }
};