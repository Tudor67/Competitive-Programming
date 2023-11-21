class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        int distinctNums = 1;
        for(int i = 1; i < N; ++i){
            if(sortedNums[i - 1] != sortedNums[i]){
                distinctNums += 1;
            }
            res += (distinctNums - 1);
        }

        return res;
    }
};