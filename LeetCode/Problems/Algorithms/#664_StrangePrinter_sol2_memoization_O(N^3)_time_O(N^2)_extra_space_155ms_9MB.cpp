class Solution {
private:
    const int INF = 1e9;

    int solve(const int L, const int R, const string& S, vector<vector<int>>& memo){
        if(L == R){
            return 1;
        }

        if(memo[L][R] != INF){
            return memo[L][R];
        }

        for(int i = L; i + 1 <= R; ++i){
            memo[L][R] = min(memo[L][R], solve(L, i, S, memo) +
                                         solve(i + 1, R, S, memo) - (int)(S[L] == S[R]));
        }

        return memo[L][R];
    }

public:
    int strangePrinter(string inputStr) {
        string s;
        for(char c: inputStr){
            if(s.empty() || s.back() != c){
                s += c;
            }
        }

        const int N = s.length();
        vector<vector<int>> memo(N, vector<int>(N, INF));
        return solve(0, N - 1, s, memo);
    }
};