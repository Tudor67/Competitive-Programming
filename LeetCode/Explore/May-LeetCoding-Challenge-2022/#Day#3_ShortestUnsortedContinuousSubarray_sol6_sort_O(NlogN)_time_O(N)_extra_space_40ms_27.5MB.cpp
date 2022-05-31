class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int firstBadPos = -1;
        int secondBadPos = -1;
        for(int i = 0; i < N; ++i){
            if(sortedNums[i] != nums[i]){
                if(firstBadPos == -1){
                    firstBadPos = i;
                }
                secondBadPos = i;
            }
        }
        
        int res = 0;
        if(firstBadPos != -1){
            res = secondBadPos - firstBadPos + 1;
        }
        
        return res;
    }
};