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
            memo[a][b] = 0.25 * (f(a - 4, b, memo) +
                                 f(a - 3, b - 1, memo) +
                                 f(a - 2, b - 2, memo) +
                                 f(a - 1, b - 3, memo));
        }
        return memo[a][b];
    }

public:
    double soupServings(int n) {
        if(n >= 5000){
            return 1;
        }
        const int SERVINGS = (n + 24) / 25;
        vector<vector<double>> memo(SERVINGS + 1, vector<double>(SERVINGS + 1, -1));
        return f(SERVINGS, SERVINGS, memo);
    }
};