class Solution {
private:
    long long modInverse(long long a, const long long MODULO){
        return fastPow(a, MODULO - 2, MODULO);
    }

    long long fastPow(long long a, long long n, const long long MODULO){
        a %= MODULO;
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

public:
    int numOfWays(vector<int>& nums) {
        const int N = nums.size();
        const long long MODULO = 1'000'000'007;

        vector<int> insertionTimeOf(N + 2, -1);
        for(int i = 0; i < N; ++i){
            insertionTimeOf[nums[i]] = i;
        }

        vector<int> parentOf(N + 1);
        set<int> visitedNums;
        visitedNums.insert(0);
        visitedNums.insert(N + 1);

        for(int num: nums){
            auto it = visitedNums.upper_bound(num);

            int pred = *prev(it);
            int succ = *it;

            if(insertionTimeOf[pred] < insertionTimeOf[succ]){
                parentOf[num] = succ;
            }else{
                parentOf[num] = pred;
            }

            visitedNums.insert(num);
        }

        vector<int> subtreeSizeOf(N + 1, 1);
        for(int i = N - 1; i >= 1; --i){
            subtreeSizeOf[parentOf[nums[i]]] += subtreeSizeOf[nums[i]];
        }

        long long nFactorial = 1;
        long long prod = 1;
        for(int i = 0; i < N; ++i){
            nFactorial = nFactorial * (i + 1) % MODULO;
            prod = prod * subtreeSizeOf[nums[i]] % MODULO;
        }

        return (nFactorial * modInverse(prod, MODULO) % MODULO - 1 + MODULO) % MODULO;
    }
};