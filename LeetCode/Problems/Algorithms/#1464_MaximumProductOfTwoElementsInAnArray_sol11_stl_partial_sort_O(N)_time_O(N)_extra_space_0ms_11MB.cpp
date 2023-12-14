class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();

        vector<int> v = nums;
        partial_sort(v.begin(), v.begin() + 2, v.end(), greater<int>());

        return (v[0] - 1) * (v[1] - 1);
    }
};