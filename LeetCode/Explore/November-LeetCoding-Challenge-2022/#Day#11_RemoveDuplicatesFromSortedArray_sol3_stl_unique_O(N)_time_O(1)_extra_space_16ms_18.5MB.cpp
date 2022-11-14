class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        int len = unique(nums.begin(), nums.end()) - nums.begin();
        return len;
    }
};