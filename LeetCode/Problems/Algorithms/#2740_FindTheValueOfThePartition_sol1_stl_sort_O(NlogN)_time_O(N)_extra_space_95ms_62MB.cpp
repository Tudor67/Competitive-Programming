class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int res = sortedNums[1] - sortedNums[0];
        for(int i = 1; i < N; ++i){
            res = min(res, sortedNums[i] - sortedNums[i - 1]);
        }
        
        return res;
    }
};