class Solution {
private:
    int f(string& s, int l, int r, vector<vector<int>>& memo){
        if(l > r){
            return 0;
        }

        if(memo[l][r] != -1){
            return memo[l][r];
        }

        int minCost = 1 + f(s, l + 1, r, memo);
        for(int i = l + 1; i <= r; ++i){
            if(s[l] == s[i]){
                minCost = min(minCost, f(s, l, i - 1, memo) + f(s, i + 1, r, memo));
            }
        }

        memo[l][r] = minCost;
        return minCost;
    }

public:
    int strangePrinter(string s) {
        const int N = s.length();
        vector<vector<int>> memo(N, vector<int>(N, -1));
        return f(s, 0, N - 1, memo);
    }
};