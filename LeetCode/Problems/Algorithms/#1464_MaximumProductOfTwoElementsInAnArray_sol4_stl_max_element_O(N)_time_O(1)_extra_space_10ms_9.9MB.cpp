class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        
        int i = max_element(nums.begin(), nums.end()) - nums.begin();
        int max1 = nums[i];
        nums[i] = INT_MIN;
        
        int j = max_element(nums.begin(), nums.end()) - nums.begin();
        int max2 = nums[j];
        nums[i] = max1;
        
        return (max1 - 1) * (max2 - 1);
    }
};