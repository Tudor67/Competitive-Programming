class Solution {
public:
    int averageValue(vector<int>& nums) {
        auto isMultipleOf6 = [](int num){
            return (num % 6 == 0);
        };
        
        int sum = accumulate(nums.begin(), nums.end(), 0,
                             [&](int s, int num){ return (isMultipleOf6(num) ? s + num : s); });
        
        int count = max(1, (int)count_if(nums.begin(), nums.end(), isMultipleOf6));
        
        return sum / count;
    }
};