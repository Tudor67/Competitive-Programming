class Solution {
private:
    double f(int a, int b, vector<vector<double>>& memo){
        if(a <= 0 && b <= 0){
            return 0.5;
        }
        if(a <= 0){
            return 1;
        }
        if(b <= 0){
            return 0;
        }
        if(memo[a][b] == -1){
            memo[a][b] = 0.25 * (f(a - 100, b, memo) +
                                 f(a - 75, b - 25, memo) +
                                 f(a - 50, b - 50, memo) +
                                 f(a - 25, b - 75, memo));
        }
        return memo[a][b];
    }

public:
    double soupServings(int n) {
        if(n >= 5000){
            return 1;
        }
        vector<vector<double>> memo(n + 1, vector<double>(n + 1, -1));
        return f(n, n, memo);
    }
};