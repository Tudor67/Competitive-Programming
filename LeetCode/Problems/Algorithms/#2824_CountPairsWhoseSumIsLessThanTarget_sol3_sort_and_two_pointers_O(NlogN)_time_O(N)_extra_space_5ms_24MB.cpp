class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        int j = N;
        for(int i = 0; i < N; ++i){
            j = max(j, i + 1);
            while(i < j - 1 && sortedNums[i] + sortedNums[j - 1] >= target){
                j -= 1;
            }
            res += (j - i - 1);
        }

        return res;
    }
};