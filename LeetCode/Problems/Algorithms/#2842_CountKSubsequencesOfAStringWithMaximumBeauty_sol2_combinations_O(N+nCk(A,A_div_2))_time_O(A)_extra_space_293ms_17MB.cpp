class Solution {
private:
    const long long MODULO = 1e9 + 7;

    void solve(int i, int k, int sum, long long prod, vector<int>& f, long long& res){
        if(k <= 0 || sum <= 0){
            if(k == 0 && sum == 0){
                res = (res + prod) % MODULO;
            }
        }else if(i + k - 1 < (int)f.size() && sum >= k){
            solve(i + 1, k, sum, prod, f, res);
            solve(i + 1, k - 1, sum - f[i], prod * f[i] % MODULO, f, res);
        }
    }

public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        const int N = s.length();

        unordered_map<char, int> charToFreq;
        for(char c: s){
            charToFreq[c] += 1;
        }

        if((int)charToFreq.size() < k){
            return 0;
        }

        vector<int> f;
        for(const pair<const char, int>& P: charToFreq){
            int charFreq = P.second;
            f.push_back(charFreq);
        }

        sort(f.rbegin(), f.rend());

        int targetSum = accumulate(f.begin(), f.begin() + k, 0);
        long long res = 0;
        solve(0, k, targetSum, 1, f, res);

        return res;
    }
};