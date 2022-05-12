class Solution {
public:
    int triangularSum(vector<int>& nums) {
        const int N = nums.size();
        
        // (i * INV[i]) mod 10 = 1, with i not in {0, 2, 4, 5, 6, 8},
        //                          because we need gcd(i, 10) == 1
        // (2 ^ i) mod 10 = POW2MOD10[i % 4], with i >= 1
        // (5 ^ i) mod 10 = 5, with i >= 1
        const vector<int> INV = {0, 1, 0, 7, 0, 0, 0, 3, 0, 9};
        const vector<int> POW2MOD10 = {6, 2, 4, 8};
        
        // nCk = n! / ((n - k)! * k!) = n * (n - 1) * ... * (n - k + 1) / (1 * 2 * ... * k)
        // nC(k+1) = n * (n - 1) * ... * (n - k + 1) * (n - k) / (1 * 2 * ... * k * (k + 1))
        //         = nCk * (n - k) / (k + 1)
        // nC(k+1) mod 10 = nCk * (n - k) * INV[(k + 1) % 10] mod 10
        // 
        // res = ((mC0 * nums[0] mod 10) + (mC1 * nums[1] mod 10) + ... + (mCm * nums[n - 1] mod 10)) mod 10,
        //       with m = N - 1
        // mCk mod 10 = ((2^exp2) * (5^exp5) * coef) mod 10
        int res = 0;
        int m = N - 1;
        int exp2 = 0;
        int exp5 = 0;
        int coef = 1;
        int k = 0;
        while(true){    
            if(exp2 == 0 || exp5 == 0){
                int mCk = coef;
                if(exp2 >= 1){
                    mCk *= POW2MOD10[exp2 % 4];
                }
                if(exp5 >= 1){
                    mCk *= 5;
                }
                res = (res + mCk * nums[k]) % 10;
            }
            
            if(k == m){
                break;
            }
            
            // Update exp2, exp5 and coef for the next step: from mCk to mC(k+1)
            // *= (m - k)
            int x = (m - k);
            while(x % 2 == 0){
                x /= 2;
                exp2 += 1;
            }
            while(x % 5 == 0){
                x /= 5;
                exp5 += 1;
            }
            coef = (coef * x) % 10;
            
            // /= (k + 1)
            int y = (k + 1);
            while(y % 2 == 0){
                y /= 2;
                exp2 -= 1;
            }
            while(y % 5 == 0){
                y /= 5;
                exp5 -= 1;
            }
            coef = (coef * INV[y % 10]) % 10;
            
            k += 1;
        }
        
        return res;
    }
};