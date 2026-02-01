class Solution {
public:
    int minPairSum(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            res = max(res, sortedNums[i] + sortedNums[j]);
        }
        
        return res;
    }
};