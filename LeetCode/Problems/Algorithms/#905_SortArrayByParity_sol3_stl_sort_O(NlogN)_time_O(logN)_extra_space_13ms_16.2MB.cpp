class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [](const int& LHS, const int& RHS){ return (LHS % 2) < (RHS % 2); });
        return nums;
    }
};