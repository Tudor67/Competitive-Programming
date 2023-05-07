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
        int j = N - 1;
        for(int i = 0; i < N && sortedNums[i] + sortedNums[i] <= target; ++i){
            while(i < j && sortedNums[i] + sortedNums[j] > target){
                j -= 1;
            }
            res = (res + pow2[j - i]) % MODULO;
        }

        return res;
    }
};