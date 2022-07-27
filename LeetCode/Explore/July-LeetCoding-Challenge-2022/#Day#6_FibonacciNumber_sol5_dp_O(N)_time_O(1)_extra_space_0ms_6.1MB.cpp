class Solution {
public:
    int fib(int n) {
        vector<int> f(3);
        
        f[0] = 0;
        f[1] = 1;
        for(int i = 2; i <= n; ++i){
            f[i % 3] = f[(i - 1) % 3] + f[(i - 2) % 3];
        }
        
        return f[n % 3];
    }
};