class Solution {
private:
    const int MODULO = 1e9 + 7;

    bool isPrime(char c){
        return (c == '2' || c == '3' || c == '5' || c == '7');
    }

    int solve(int index, const string& S, int k, int minLength, vector<vector<int>>& memo){
        const int N = S.length();
        if(k == 1 && index <= N - 1){
            return 1;
        }
        if(index >= N){
            return 0;
        }
        if(memo[index][k] >= 0){
            return memo[index][k];
        }
        int res = solve(index + 1, S, k, minLength, memo);
        if(!isPrime(S[index]) && index + 1 < N && isPrime(S[index + 1])){
            res = (res + solve(index + minLength, S, k - 1, minLength, memo)) % MODULO;
        }
        memo[index][k] = res;
        return res;
    }

public:
    int beautifulPartitions(string s, int k, int minLength) {
        const int N = s.length();

        minLength = max(2, minLength);

        if(k * minLength > N || !isPrime(s[0]) || isPrime(s[N - 1])){
            return 0;
        }

        vector<vector<int>> memo(N, vector<int>(k + 1, -1));
        return solve(minLength - 1, s, k, minLength, memo);
    }
};