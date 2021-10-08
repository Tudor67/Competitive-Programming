class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(2);
        f[0] = 1;
        f[1] = 1;
        for(int i = 2; i <= n; ++i){
            f[i % 2] = f[(i - 1) % 2] + f[(i - 2) % 2];
        }
        return f[n % 2];
    }
};