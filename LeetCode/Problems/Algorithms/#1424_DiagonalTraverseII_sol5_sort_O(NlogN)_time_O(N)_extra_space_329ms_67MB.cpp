class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {        
        vector<pair<int, int>> v;
        for(int row = 0; row < (int)nums.size(); ++row){
            for(int col = 0; col < (int)nums[row].size(); ++col){
                v.emplace_back(row, col);
            }
        }
        
        sort(v.begin(), v.end(),
             [](const pair<int, int>& LHS, const pair<int, int>& RHS){
                 int lhsDiag = LHS.first + LHS.second;
                 int lhsCol = LHS.second;
                 int rhsDiag = RHS.first + RHS.second;
                 int rhsCol = RHS.second;
                 return (lhsDiag < rhsDiag || (lhsDiag == rhsDiag && lhsCol < rhsCol));
             });
        
        const int N = v.size();
        vector<int> diagonalOrder(N);
        for(int i = 0; i < N; ++i){
            int row = v[i].first;
            int col = v[i].second;
            diagonalOrder[i] = nums[row][col];
        }
        
        return diagonalOrder;
    }
};