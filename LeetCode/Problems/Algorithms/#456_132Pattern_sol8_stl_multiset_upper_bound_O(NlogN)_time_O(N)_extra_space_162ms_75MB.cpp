class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int N = nums.size();

        int prefMin = nums[0];
        multiset<int> suffixValues(nums.begin() + 1, nums.end());

        for(int i = 1; i + 1 < N; ++i){
            prefMin = min(prefMin, nums[i - 1]);
            suffixValues.erase(suffixValues.find(nums[i]));

            if(prefMin < nums[i]){
                multiset<int>::iterator it = suffixValues.upper_bound(prefMin);
                if(it != suffixValues.end() && nums[i] > *it){
                    return true;
                }
            }
        }

        return false;
    }
};