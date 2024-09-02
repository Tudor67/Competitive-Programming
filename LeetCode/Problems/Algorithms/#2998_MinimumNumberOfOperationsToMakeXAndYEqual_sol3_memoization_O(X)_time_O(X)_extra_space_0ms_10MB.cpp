class Solution {
private:
    int f(int x, int y, vector<int>& memo){
        if(x <= y){
            return (y - x);
        }

        if(memo[x] != -1){
            return memo[x];
        }

        int minOps = x - y;
        minOps = min(minOps, 1 + (x % 5) + f(x / 5, y, memo));
        minOps = min(minOps, 1 + (5 - (x % 5)) + f(1 + x / 5, y, memo));
        minOps = min(minOps, 1 + (x % 11) + f(x / 11, y, memo));
        minOps = min(minOps, 1 + (11 - (x % 11)) + f(1 + x / 11, y, memo));

        memo[x] = minOps;
        return minOps;
    }

public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x <= y){
            return (y - x);
        }
        vector<int> memo(x + 1, -1);
        return f(x, y, memo);
    }
};