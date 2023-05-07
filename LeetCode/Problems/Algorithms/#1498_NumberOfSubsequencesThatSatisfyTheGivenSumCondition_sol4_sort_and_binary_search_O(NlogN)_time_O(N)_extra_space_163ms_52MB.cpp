class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> pow2(N);
        pow2[0] = 1;
        for(int i = 1; i < N; ++i){
            pow2[i] = (2 * pow2[i - 1]) % MODULO;
        }

        int res = 0;
        for(int i = 0; i < N && sortedNums[i] + sortedNums[i] <= target; ++i){
            int j = upper_bound(sortedNums.begin(), sortedNums.end(), target - sortedNums[i]) - sortedNums.begin();
            res = (res + pow2[j - i - 1]) % MODULO;
        }

        return res;
    }
};