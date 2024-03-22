class Solution {
private:
    int f(int l, int r, int flippedStart, string& s, int x, vector<vector<int>>& memo){
        if(l <= r && (s[l] ^ flippedStart) == '0'){
            l += 1;
            while(l <= r && s[l] == '0'){
                l += 1;
            }
        }

        while(l <= r && s[r] == '0'){
            r -= 1;
        }

        if(l > r){
            return 0;
        }

        if(memo[l][r] != -1){
            return memo[l][r];
        }

        int res = 1 + f(l + 1, r, 1, s, x, memo);
        int ones = 1;
        for(int i = l + 1; i <= r; ++i){
            ones += (int)(s[i] == '1');
            if(s[i] == '1' && ones % 2 == 0){
                int ops = x + f(l + 1, i - 1, 0, s, x, memo) + f(i + 1, r, 0, s, x, memo);
                res = min(res, ops);
            }
        }

        memo[l][r] = res;
        return res;
    }

public:
    int minOperations(string s1, string s2, int x) {
        const int N = s1.length();

        string s(N, '0');
        for(int i = 0; i < N; ++i){
            if(s1[i] != s2[i]){
                s[i] = '1';
            }
        }

        if(count(s.begin(), s.end(), '1') % 2 == 1){
            return -1;
        }

        vector<vector<int>> memo(N, vector<int>(N, -1));
        return f(0, N - 1, 0, s, x, memo);
    }
};