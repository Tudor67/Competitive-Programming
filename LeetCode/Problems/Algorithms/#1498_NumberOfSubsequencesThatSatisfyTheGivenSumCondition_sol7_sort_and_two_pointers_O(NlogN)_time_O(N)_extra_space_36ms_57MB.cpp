class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> pow2(N + 1, 1);
        for(int i = 1; i <= N; ++i){
            pow2[i] = pow2[i - 1] * 2 % MODULO;
        }

        int res = 0;
        int j = N - 1;
        for(int i = 0; i < N; ++i){
            while(j >= 0 && sortedNums[i] + sortedNums[j] > target){
                j -= 1;
            }
            if(i <= j){
                res += pow2[j - i];
                res %= MODULO;
            }
        }

        return res;
    }
};