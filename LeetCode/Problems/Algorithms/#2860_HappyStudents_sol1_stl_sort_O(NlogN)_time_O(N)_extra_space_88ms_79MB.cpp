class Solution {
public:
    int countWays(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        for(int i = 0; i < N; ++i){
            int groupSize = i + 1;
            if(groupSize > sortedNums[i]){
                if(i == N - 1 || groupSize < sortedNums[i + 1]){
                    res += 1;
                }
            }
        }

        if(sortedNums[0] >= 1){
            res += 1;
        }

        return res;
    }
};