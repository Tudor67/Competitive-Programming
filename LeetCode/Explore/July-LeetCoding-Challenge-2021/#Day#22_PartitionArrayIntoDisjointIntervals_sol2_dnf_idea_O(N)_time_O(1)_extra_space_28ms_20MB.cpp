class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        const int N = nums.size();
        
        // Similar to Dutch National Flag Algorithm
        // At step i:
        // - we have 3 partitions: nums[0 .. l], nums[l + 1 .. i] and nums[i + 1 .. N - 1];
        // - max(nums[0 .. l]) <= min(nums[l + 1 .. i]);
        // - update l to i if and only if max(nums[0 .. l]) > nums[i];
        // - nums[i + 1 .. N - 1] will be processed at next steps;
        int l = 0; 
        int lMax = nums[0];
        int prefMax = nums[0];
        for(int i = 1; i < N; ++i){
            if(lMax > nums[i]){
                lMax = prefMax;
                l = i;
            }
            prefMax = max(prefMax, nums[i]);
        }
        
        return l + 1;
    }
};