class Solution {
private:
    double dfs(int a, int b, unordered_map<int, double>& memo){
        if(a == 0 && b == 0){
            return 0.5;
        }
        if(a == 0 && b != 0){
            return 1;
        }
        if(a != 0 && b == 0){
            return 0;
        }
        int state = (a << 14) | b;
        if(!memo.count(state)){
            memo[state] = 0.25 * (dfs(max(0, a - 100), b, memo) +
                                  dfs(max(0, a - 75), max(0, b - 25), memo) +
                                  dfs(max(0, a - 50), max(0, b - 50), memo) +
                                  dfs(max(0, a - 25), max(0, b - 75), memo));
        }
        return memo[state];
    }

public:
    double soupServings(int n) {
        if(n >= 5000){
            return 1;
        }
        unordered_map<int, double> memo;
        return dfs(n, n, memo);
    }
};