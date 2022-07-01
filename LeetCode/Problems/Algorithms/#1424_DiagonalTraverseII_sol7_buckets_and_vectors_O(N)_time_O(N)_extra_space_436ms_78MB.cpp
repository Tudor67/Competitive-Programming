class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxDiagIdx = 0;
        for(int row = 0; row < (int)nums.size(); ++row){
            int cols = nums[row].size();
            maxDiagIdx = max(maxDiagIdx, row + cols - 1);
        }
        
        vector<vector<int>> buckets(maxDiagIdx + 1);
        int size = 0;
        for(int row = 0; row < (int)nums.size(); ++row){
            for(int col = 0; col < (int)nums[row].size(); ++col){
                buckets[row + col].push_back(nums[row][col]);
                size += 1;
            }
        }
        
        vector<int> diagonalOrder;
        diagonalOrder.reserve(size);
        for(int diagIdx = 0; diagIdx <= maxDiagIdx; ++diagIdx){
            const vector<int>& REV_DIAGONAL = buckets[diagIdx];
            for(vector<int>::const_reverse_iterator rit = REV_DIAGONAL.rbegin(); rit != REV_DIAGONAL.rend(); ++rit){
                diagonalOrder.push_back(*rit);
            }
        }
        
        return diagonalOrder;
    }
};