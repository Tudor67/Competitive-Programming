class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());
        return gcd(*minIt, *maxIt);
    }
};