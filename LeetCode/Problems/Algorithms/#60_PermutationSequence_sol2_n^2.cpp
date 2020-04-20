class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1);
        factorial[0] = 1;
        for(int i = 1; i <= n; ++i){
            factorial[i] = i * factorial[i - 1];
        }
        
        vector<int> p(n + 1);
        vector<bool> vis(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(!vis[j]){
                    if(factorial[n - i] < k){
                        k -= factorial[n - i];
                    }else{
                        p[i] = j;
                        vis[j] = 1;
                        break;
                    }
                }
            }
        }
        
        string sol(n, '0');
        for(int i = 0; i < n; ++i){
            sol[i] = char(p[i + 1] + '0');
        }
        
        return sol;
    }
};