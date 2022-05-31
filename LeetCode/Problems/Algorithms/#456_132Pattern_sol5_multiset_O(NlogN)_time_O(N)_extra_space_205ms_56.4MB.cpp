class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int N = nums.size();
        
        if(N <= 2){
            return false;
        }
        
        int prefMin = nums[0];
        multiset<int> rightValues(nums.begin() + 2, nums.end());
        for(int i = 1; i + 1 < N; ++i){
            if(prefMin < nums[i]){
                multiset<int>::iterator it = rightValues.upper_bound(prefMin);
                if(it != rightValues.end() && nums[i] > *it){
                    return true;
                }
            }
            prefMin = min(prefMin, nums[i]);
            rightValues.erase(rightValues.find(nums[i + 1]));
        }
        
        return false;
    }
};