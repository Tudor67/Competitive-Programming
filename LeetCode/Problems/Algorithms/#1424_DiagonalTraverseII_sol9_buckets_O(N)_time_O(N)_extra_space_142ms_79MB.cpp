class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        const int ROWS = nums.size();

        int maxSum = 0;
        int totalSize = 0;
        for(int row = 0; row < ROWS; ++row){
            int sum = row + (int)nums[row].size() - 1;
            maxSum = max(maxSum, sum);
            totalSize += nums[row].size();
        }

        vector<vector<int>> buckets(maxSum + 1);
        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = (int)nums[row].size() - 1; col >= 0; --col){
                int sum = row + col;
                buckets[sum].push_back(nums[row][col]);
            }
        }

        vector<int> res;
        res.reserve(totalSize);
        for(int sum = 0; sum <= maxSum; ++sum){
            for(int val: buckets[sum]){
                res.push_back(val);
            }
        }

        return res;
    }
};