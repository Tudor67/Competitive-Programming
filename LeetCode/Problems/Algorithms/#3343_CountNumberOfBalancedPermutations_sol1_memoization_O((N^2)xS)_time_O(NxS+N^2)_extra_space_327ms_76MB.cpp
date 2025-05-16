class Solution {
private:
    const int MODULO = 1'000'000'007;
    vector<vector<long long>> comb;

    long long f(int digit, int even, int odd, int balance, vector<int>& freq, unordered_map<int, int>& memo){
        if(even == 0 && odd == 0 && balance == 0){
            return 1;
        }
        
        if(digit < 0 || even < 0 || odd < 0){
            return 0;
        }

        int state = even | (odd << 7) | ((balance + 500) << 14);
        if(memo.count(state)){
            return memo[state];
        }

        long long res = 0;
        for(int i = 0; i <= min(freq[digit], even); ++i){
            res += comb[even][i] * comb[odd][freq[digit] - i] % MODULO *
                   f(digit - 1, even - i, odd - (freq[digit] - i), balance + digit * (2 * i - freq[digit]), freq, memo) % MODULO;
            res %= MODULO;
        }

        memo[state] = res;
        return res;
    }

public:
    int countBalancedPermutations(string s) {
        const int N = s.length();

        // Special case: odd totalSum
        int totalSum = 0;
        for(char c: s){
            totalSum += (c - '0');
        }

        if(totalSum % 2 == 1){
            return 0;
        }

        // Memoization
        vector<int> freq(10);
        for(char c: s){
            freq[c - '0'] += 1;
        }

        comb.assign(N + 1, vector<long long>(N + 1));
        comb[0][0] = 1;
        for(int i = 1; i < comb.size(); ++i){
            comb[i][0] = 1;
            for(int j = 1; j <= i; ++j){
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MODULO;
            }
        }

        unordered_map<int, int> memo;
        return f(9, N - N / 2, N / 2, 0, freq, memo);
    }
};