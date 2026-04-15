class Solution {
private:
    const long long MODULO = 1'000'000'007;

    long long fastPow(long long a, long long n){
        long long res = 1;
        while(n > 0){
            if(n & 1){
                res = res * a % MODULO;
            }
            a = a * a % MODULO;
            n >>= 1;
        }
        return res;
    }

    long long modInverse(long long a){
        return fastPow(a, MODULO - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();
        const int B = floor(sqrt(N)) + 1;

        // Case 1: queries with k > B
        vector<long long> coeffs(N, 1);
        for(const vector<int>& QUERY: queries){
            int l = QUERY[0];
            int r = QUERY[1];
            int k = QUERY[2];
            int v = QUERY[3];
            if(k > B){
                for(int i = l; i <= r; i += k){
                    coeffs[i] = coeffs[i] * v % MODULO;
                }
            }
        }

        // Case 2: queries with k <= B
        vector<vector<int>> groups(B + 1);
        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            int l = queries[queryIndex][0];
            int r = queries[queryIndex][1];
            int k = queries[queryIndex][2];
            if(k <= B){
                groups[k].push_back(queryIndex);
            }
        }

        vector<long long> delta(N + 1);
        for(int k = 1; k <= B; ++k){
            fill(delta.begin(), delta.end(), 1);

            for(int queryIndex: groups[k]){
                int l = queries[queryIndex][0];
                int r = queries[queryIndex][1];
                int v = queries[queryIndex][3];

                int rOut = l + ((r - l) / k) * k + k;

                delta[l] = delta[l] * v % MODULO;
                delta[min(rOut, N)] = delta[min(rOut, N)] * modInverse(v) % MODULO;
            }

            for(int i = 0; i < N; ++i){
                if(i >= k){
                    delta[i] = delta[i - k] * delta[i] % MODULO;
                }
                coeffs[i] = coeffs[i] * delta[i] % MODULO;
            }
        }

        // Compute resXOR
        int resXOR = 0;
        for(int i = 0; i < N; ++i){
            int num = nums[i] * coeffs[i] % MODULO;
            resXOR ^= num;
        }

        return resXOR;
    }
};