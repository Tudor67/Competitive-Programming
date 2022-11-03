class Solution {
public:
    int findMaxK(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int l = 0;
        int r = N - 1;
        while(l < r){
            if(sortedNums[l] + sortedNums[r] < 0){
                l += 1;
            }else if(sortedNums[l] + sortedNums[r] > 0){
                r -= 1;
            }else{
                return sortedNums[r];
            }
        }
        
        return -1;
    }
};