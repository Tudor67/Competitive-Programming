class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        int l = 0;
        int r = N - 1;
        while(l < r){
            if(sortedNums[l] + sortedNums[r] < target){
                res += (r - l);
                l += 1;
            }else{
                r -= 1;
            }
        }
        
        return res;
    }
};