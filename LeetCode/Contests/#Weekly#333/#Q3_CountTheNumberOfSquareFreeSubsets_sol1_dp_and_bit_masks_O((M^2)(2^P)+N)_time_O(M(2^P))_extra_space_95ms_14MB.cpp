class Solution {
private:
    bool isPrime(int num){
        if(num <= 1){
            return false;
        }
        for(int i = 2; i * i <= num; ++i){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

    bool isSquareFree(int num){
        for(int i = 2; i * i <= num; ++i){
            if(num % (i * i) == 0){
                return false;
            }
        }
        return true;
    }

    int getPrimeMask(int num, vector<int>& primes){
        int mask = 0;
        for(int i = 0; i < (int)primes.size(); ++i){
            if(num % primes[i] == 0){
                mask |= (1 << i);
            }
        }
        return mask;
    }

public:
    int squareFreeSubsets(vector<int>& nums) {
        // Step 1: collect only square free nums in vector v (and remember their count);
        //         use a map to keep nums in ascending order;
        map<int, int> count;
        for(int num: nums){
            if(isSquareFree(num)){
                count[num] += 1;
            }
        }

        vector<int> v;
        for(const pair<int, int>& P: count){
            int num = P.first;
            v.push_back(num);
        }

        // Step 2: compute and store the prime numbers from range [2 .. MAX_NUM];
        //         compute the prime factorization of each v[i] in primeMasks[i];
        //         if the xth prime is in the factorization of v[i]
        //         then the xth bit of primeMasks[i] is set to 1;
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        vector<int> primes;
        for(int i = 2; i <= MAX_NUM; ++i){
            if(isPrime(i)){
                primes.push_back(i);
            }
        }

        const int V_SIZE = v.size();
        const int P = primes.size();
        const int PRIMES_FULL_MASK = (1 << P) - 1;
        vector<int> primeMasks(V_SIZE);
        for(int i = 0; i < V_SIZE; ++i){
            primeMasks[i] = getPrimeMask(v[i], primes);
        }

        // Step 3: DP
        //         dp[i][mask]: number of square-free non-empty subsets of the array v[0 .. i]
        //                      such that the product of its elements is described by the bitmask mask;
        //                      a non zero bit of the mask represents the index of a prime that is
        //                      included in the product of the subset elements;
        //         Example:
        //         dp[2][12]: number of square-free non-empty subsets of the array v[0 .. 2]
        //                    such that the product of its elements is primes[3] * primes[2];
        //                    why primes[3] and primes[2]?
        //                    bitmask of integer 12 is (1100) => the product includes the primes
        //                                                       at indices 2 and 3 (from right to left)
        const int MODULO = 1e9 + 7;
        vector<vector<long long>> dp(V_SIZE, vector<long long>(PRIMES_FULL_MASK + 1));
        for(int i = 0; i < V_SIZE; ++i){
            if(v[i] == 1){
                int p = 1;
                for(int i = 1; i <= count[1]; ++i){
                    p = (p * 2) % MODULO;
                }
                dp[i][primeMasks[i]] = (p - 1 + MODULO) % MODULO;
            }else{
                dp[i][primeMasks[i]] = count[v[i]];
                for(int j = 0; j < i; ++j){
                    for(int jMask = 0; jMask <= PRIMES_FULL_MASK; ++jMask){
                        if((primeMasks[i] & jMask) == 0){
                            int newMask = primeMasks[i] | jMask;
                            dp[i][newMask] = (dp[i][newMask] + dp[j][jMask] * count[v[i]] % MODULO) % MODULO;
                        }
                    }
                }
            }
        }

        long long res = 0;
        for(int i = 0; i < V_SIZE; ++i){
            for(int mask = 0; mask <= PRIMES_FULL_MASK; ++mask){
                res = (res + dp[i][mask]) % MODULO;
            }
        }

        return res;
    }
};