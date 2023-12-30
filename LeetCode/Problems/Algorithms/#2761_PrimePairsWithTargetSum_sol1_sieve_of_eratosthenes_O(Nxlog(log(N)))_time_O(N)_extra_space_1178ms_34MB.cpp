class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= n; ++i){
            if(isPrime[i]){
                for(int j = i + i; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        
        vector<vector<int>> res;
        for(int i = 2; i <= n - 2 && i <= n - i; ++i){
            if(isPrime[i] && isPrime[n - i]){
                res.push_back({i, n - i});
            }
        }
        
        return res;
    }
};