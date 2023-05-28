class Solution {
private:
    int solve(int l, int r, vector<int>& sortedCuts, vector<vector<int>>& memo){
        if(l + 1 >= r){
            memo[l][r] = 0;
        }else if(memo[l][r] == -1){
            int res = INT_MAX;
            for(int i = l + 1; i + 1 <= r; ++i){
                int cost = sortedCuts[r] - sortedCuts[l] +
                           solve(l, i, sortedCuts, memo) + solve(i, r, sortedCuts, memo);
                res = min(res, cost);
            }
            memo[l][r] = res;
        }
        return memo[l][r];
    }

public:
    int minCost(int N, vector<int>& cuts) {
        vector<int> sortedCuts = cuts;

        sortedCuts.push_back(0);
        sortedCuts.push_back(N);
        sort(sortedCuts.begin(), sortedCuts.end());

        const int C = sortedCuts.size();
        vector<vector<int>> memo(C, vector<int>(C, -1));
        return solve(0, C - 1, sortedCuts, memo);
    }
};