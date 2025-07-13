class Solution {
private:
    void add(int& a, int b, const int MODULO){
        a = (a + b) % MODULO;
    }

public:
    int possibleStringCount(string word, int k) {
        const int N = word.length();
        const int MODULO = 1'000'000'007;
        
        vector<int> groups;

        int l = 0;
        while(l < N){
            int r = l;
            while(r < N && word[l] == word[r]){
                r += 1;
            }
            groups.push_back(r - l);
            l = r;
        }

        int res = 1;
        for(long long g: groups){
            res = (res * g) % MODULO;
        }

        if((int)groups.size() >= k){
            return res;
        }

        vector<int> dp(k + 1);
        dp[0] = 1;

        for(int g: groups){
            int wSum = 0;
            for(int sum = k - 1; sum >= max(0, k - (g - 1)); --sum){
                add(wSum, dp[sum], MODULO);
            }
            for(int sum = k; sum >= 1; --sum){
                add(dp[sum], wSum, MODULO);
                add(wSum, MODULO - dp[sum - 1], MODULO);
                if(sum >= g){
                    add(wSum, dp[sum - g], MODULO);
                }
            }
        }
        
        for(int sum = 0; sum <= k - 1 - (int)groups.size(); ++sum){
            add(res, MODULO - dp[sum], MODULO);
        }

        return res;
    }
};