class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        long long res = 1;
        int groupSize = 0;
        for(int i = 0; i < N; ++i){
            if(res * sortedNums[i] > 0 || (i + 1 < N && sortedNums[i + 1] < 0)){
                res *= sortedNums[i];
                groupSize += 1;
            }
        }

        if(groupSize == 0){
            res = sortedNums[N - 1];
        }

        return res;
    }
};