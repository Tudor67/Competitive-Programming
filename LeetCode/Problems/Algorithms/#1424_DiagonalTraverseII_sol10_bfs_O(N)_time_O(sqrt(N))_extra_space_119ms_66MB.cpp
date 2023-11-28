class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;

        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            res.push_back(nums[row][col]);

            if(row + 1 < (int)nums.size() && col == 0){
                q.push({row + 1, col});
            }

            if(col + 1 < (int)nums[row].size()){
                q.push({row, col + 1});
            }
        }

        return res;
    }
};