class Solution {
private:
    const int MODULO = 1e9 + 7;

    int solve(int zero, int one, int length, vector<int>& memo){
        if(length < 0){
            return 0;
        }
        if(length == 0){
            return 1;
        }
        if(memo[length] >= 0){
            return memo[length];
        }
        int zeroContrib = solve(zero, one, length - zero, memo);
        int oneContrib = solve(zero, one, length - one, memo);
        memo[length] = (zeroContrib + oneContrib) % MODULO;
        return memo[length];
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int res = 0;
        vector<int> memo(high + 1, -1);
        for(int length = low; length <= high; ++length){
            res = (res + solve(zero, one, length, memo)) % MODULO;
        }
        return res;
    }
};