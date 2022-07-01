class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        return (sortedNums[N - 2] - 1) * (sortedNums[N - 1] - 1);
    }
};