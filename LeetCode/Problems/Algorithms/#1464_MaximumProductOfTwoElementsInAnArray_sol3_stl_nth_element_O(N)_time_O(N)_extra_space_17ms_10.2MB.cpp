class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> partitionedNums = nums;
        nth_element(partitionedNums.begin(), partitionedNums.end() - 2, partitionedNums.end());
        
        return (partitionedNums[N - 2] - 1) * (partitionedNums[N - 1] - 1);
    }
};