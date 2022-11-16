class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0,
                             [](int s, int num){ return (num % 6 == 0 ? s + num : s); });
        int count = max(1, (int)count_if(nums.begin(), nums.end(),
                                         [](int num){ return (num % 6 == 0); }));
        return sum / count;
    }
};