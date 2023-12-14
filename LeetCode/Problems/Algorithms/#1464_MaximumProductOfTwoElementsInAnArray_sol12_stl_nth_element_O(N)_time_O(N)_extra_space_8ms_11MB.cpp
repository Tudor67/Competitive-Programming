class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();

        vector<int> v = nums;
        nth_element(v.begin(), v.end() - 2, v.end());

        return (v[N - 2] - 1) * (v[N - 1] - 1);
    }
};