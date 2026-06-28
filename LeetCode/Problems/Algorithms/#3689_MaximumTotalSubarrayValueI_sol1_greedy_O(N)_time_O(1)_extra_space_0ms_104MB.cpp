class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        return (MAX_NUM - MIN_NUM) * (long long)k;
    }
};