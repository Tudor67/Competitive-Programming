class Solution {
private:
    int count(int pos, int n, int visMask, vector<vector<int>>& memo){
        if(pos == -1){
            return 1;
        }
        if(memo[pos][visMask] != -1){
            return memo[pos][visMask];
        }
        memo[pos][(1 << n) - 1] = 0;
        for(int i = 0; i < n; ++i){
            if(!((visMask >> i) & 1) && ((pos + 1) % (i + 1) == 0 || (i + 1) % (pos + 1) == 0)){
                memo[pos][(1 << n) - 1] += count(pos - 1, n, visMask | (1 << i), memo);
            }
        }
        return memo[pos][(1 << n) - 1];
    }
    
public:
    int countArrangement(int n) {
        vector<vector<int>> memo(n, vector<int>(1 << n, -1));
        return count(n - 1, n, 0, memo);
    }
};