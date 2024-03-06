class Solution {
public:
    int countWays(vector<int>& nums) {
        const int N = nums.size();

        vector<int> freq(N);
        for(int num: nums){
            freq[num] += 1;
        }

        vector<int> sortedNums;
        sortedNums.reserve(N);
        for(int num = 0; num < N; ++num){
            for(int i = 1; i <= freq[num]; ++i){
                sortedNums.push_back(num);
            }
        }

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