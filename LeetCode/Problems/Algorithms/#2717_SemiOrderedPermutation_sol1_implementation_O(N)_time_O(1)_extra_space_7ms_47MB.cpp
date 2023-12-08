class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        const int N = nums.size();
        
        int i = find(nums.begin(), nums.end(), 1) - nums.begin();
        int j = find(nums.begin(), nums.end(), N) - nums.begin();
        
        int ops = i + (N - 1 - j);
        if(j < i){
            ops -= 1;
        }
        
        return ops;
    }
};