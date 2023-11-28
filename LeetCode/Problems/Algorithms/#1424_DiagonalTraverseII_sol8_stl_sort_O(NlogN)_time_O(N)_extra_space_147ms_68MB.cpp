class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        const int ROWS = nums.size();

        vector<pair<int, int>> v;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < (int)nums[row].size(); ++col){
                v.push_back({row + col, col});
            }
        }

        sort(v.begin(), v.end());

        vector<int> res;
        res.reserve(v.size());
        for(const pair<int, int>& P: v){
            int row = P.first - P.second;
            int col = P.second;
            res.push_back(nums[row][col]);
        }

        return res;
    }
};