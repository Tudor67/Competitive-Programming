class Solution {
public:
    int minOperations(vector<int>& initialNums) {
        const int N = initialNums.size();
        
        // sort and de-duplicate initial nums
        vector<int> nums = initialNums;
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        
        // fix the first num, binary search the last num (i.e., the target), compute ops, update minOps
        int minOps = N - 1;
        for(int i = 0; i < (int)nums.size(); ++i){
            int firstNum = nums[i];
            int lastNum = nums[i] + N - 1;
            int j = lower_bound(nums.begin() + i, nums.end(), lastNum) - nums.begin();
            int ops = N - (j - i + 1);
            if(j == (int)nums.size() || nums[j] != lastNum){
                ops += 1;
            }
            minOps = min(minOps, ops);
        }
        
        return minOps;
    }
};