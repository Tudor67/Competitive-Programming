class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int N = nums.size();
        
        int firstBadPos = -1;
        int suffMin = nums[N - 1];
        for(int i = N - 1; i >= 0; --i){
            if(nums[i] > suffMin){
                firstBadPos = i;
            }
            suffMin = min(suffMin, nums[i]);
        }
        
        int secondBadPos = -1;
        int prefMax = nums[0];
        for(int i = 0; i < N; ++i){
            if(prefMax > nums[i]){
                secondBadPos = i;
            }
            prefMax = max(prefMax, nums[i]);
        }
        
        int res = 0;
        if(firstBadPos != -1){
            res = secondBadPos - firstBadPos + 1;
        }
        
        return res;
    }
};