class Solution {
private:
    long long nCk(long long n, long long k, const long long MODULO){
        long long res = 1;
        for(long long i = 1; i <= k; ++i){
            res *= (n - k + i);
            res /= i;
        }
        return res % MODULO;
    }

public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        const int N = s.length();
        const long long MODULO = 1e9 + 7;

        // Step 1: compute freq of each char
        unordered_map<char, int> charToFreq;
        for(char c: s){
            charToFreq[c] += 1;
        }

        // Step 2: if the number of unique chars < k => return 0;
        if((int)charToFreq.size() < k){
            return 0;
        }

        // Step 3: store freq of each char in vector f
        vector<int> f;
        f.reserve(charToFreq.size());
        for(const pair<const char, int>& P: charToFreq){
            int charFreq = P.second;
            f.push_back(charFreq);
        }

        // Step 4: sort f in decreasing order
        sort(f.rbegin(), f.rend());

        // Step 5: use sorted frequencies from vector f
        //         to take K unique chars (most frequent chars)
        //         and compute the cartesian product of f[0 .. k - 1]: f[0] * f[1] * ... * f[k - 1]
        //         attention: the least frequent elements x with frequency f[k - 1]
        //                    can be replaced in nCk(xTotalCount, xNeededCount) ways
        //                    by other elements from f[k ..] that have the same frequency f[k - 1]
        //                    xTotalCount is the total count of f[k - 1] in f
        //                    xNeededCount is the count of f[k - 1] in f[0 .. k - 1]
        long long res = 1;
        for(int i = 0; i < k; ++i){
            res = res * f[i] % MODULO;
        }
        
        long long xTotalCount = count(f.begin(), f.end(), f[k - 1]);
        long long xNeededCount = count(f.begin(), f.begin() + k, f[k - 1]);
        res = res * nCk(xTotalCount, xNeededCount, MODULO) % MODULO;

        return res;
    }
};