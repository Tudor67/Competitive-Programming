class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MODULO = 1'000'000'007;
        
        vector<int> share(n + 1);
        vector<int> know(n + 1);

        share[1] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = i; j <= min(i + forget - 1, n); ++j){
                know[j] = (know[j] + share[i]) % MODULO;
                if(j - i >= delay){
                    share[j] = (share[j] + share[i]) % MODULO;
                }
            }
        }

        return know[n];
    }
};