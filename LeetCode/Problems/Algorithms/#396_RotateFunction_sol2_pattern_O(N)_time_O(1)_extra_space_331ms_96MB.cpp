class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        /*
          For nums = {A, B, C, D};
          N = 4;
          TOTAL_SUM = A + B + C + D;
          
          F[0] = 0 * A + 1 * B + 2 * C + 3 * D;
          F[1] = 1 * A + 2 * B + 3 * C + 0 * D;
          F[2] = 2 * A + 3 * B + 0 * C + 1 * D;
          F[3] = 3 * A + 0 * B + 1 * C + 2 * D;
          
          F[1] = F[0] + TOTAL_SUM - 4 * D;
          F[2] = F[1] + TOTAL_SUM - 4 * C;
          F[3] = F[2] + TOTAL_SUM - 4 * B;
          
          The result is max(F[0], F[1], F[2], F[3]).
        */
        const int N = nums.size();
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0LL);
        
        long long f = 0;
        for(int i = 1; i < N; ++i){
            f += i * nums[i];
        }
        
        long long res = f;
        for(int i = N - 1; i >= 1; --i){
            f += TOTAL_SUM - N * nums[i];
            res = max(res, f);
        }
        
        return res;
    }
};