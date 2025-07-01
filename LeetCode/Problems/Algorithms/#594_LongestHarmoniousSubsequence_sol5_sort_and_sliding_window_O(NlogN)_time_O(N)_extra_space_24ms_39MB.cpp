class Solution {
public:
    int findLHS(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int maxLen = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            while(l < r && sortedNums[r] - sortedNums[l] > 1){
                l += 1;
            }
            if(sortedNums[r] - sortedNums[l] == 1){
                maxLen = max(maxLen, r - l + 1);
            }
        }

        return maxLen;
    }
};