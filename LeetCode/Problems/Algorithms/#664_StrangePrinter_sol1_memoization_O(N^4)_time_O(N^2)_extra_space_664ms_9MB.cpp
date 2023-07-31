class Solution {
private:
    const int A = 26;
    const char FIRST_CHAR = 'a';
    const int INF = 1e9;

    int solve(const int L, const int R, const string& S, vector<vector<int>>& posOf, vector<vector<int>>& memo){
        if(L > R){
            return 0;
        }

        if(memo[L][R] != INF){
            return memo[L][R];
        }

        int res = INF;
        for(int i = L; i <= R; ++i){
            res = min(res, solve(L, i - 1, S, posOf, memo) +
                           1 +
                           solve(i + 1, R, S, posOf, memo));

            if(i + 1 <= R && S[i] != S[i + 1] && !posOf[S[i + 1] - FIRST_CHAR].empty()){
                const vector<int>& V = posOf[S[i + 1] - FIRST_CHAR];
                int startIdx = lower_bound(V.begin(), V.end(), L) - V.begin();
                int endIdx = upper_bound(V.begin(), V.end(), i) - V.begin();
                for(int idx = startIdx; idx < endIdx; ++idx){
                    int prevPos = V[idx];
                    res = min(res, solve(L, prevPos, S, posOf, memo) +
                                   solve(prevPos + 1, i, S, posOf, memo) +
                                   solve(i + 1, R, S, posOf, memo) - 1);
                }
            }
        }

        memo[L][R] = res;
        return res;
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
        vector<vector<int>> posOf(A);
        for(int i = 0; i < N; ++i){
            posOf[s[i] - FIRST_CHAR].push_back(i);
        }

        vector<vector<int>> memo(N, vector<int>(N, INF));
        return solve(0, N - 1, s, posOf, memo);
    }
};