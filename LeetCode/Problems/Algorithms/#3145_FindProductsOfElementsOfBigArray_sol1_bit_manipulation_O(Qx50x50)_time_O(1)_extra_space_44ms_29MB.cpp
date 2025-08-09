class Solution {
private:
    const int MAX_BIT = 50;

    long long countOneBits(long long x, long long bit){
        long long blockSize = (1LL << bit);
        long long blocks = (x + 1) / blockSize;
        long long oneBits = (blocks / 2) * blockSize;
        if(blocks % 2 == 1){
            oneBits += (x + 1) % blockSize;
        }
        return oneBits;
    }

    long long countOneBits(long long x){
        long long oneBits = 0;
        for(int bit = 0; (1LL << bit) <= x; ++bit){
            oneBits += countOneBits(x, bit);
        }
        return oneBits;
    }

    long long binarySearchMaxValidNum(long long maxOneBits){
        long long l = 0;
        long long r = (1LL << (MAX_BIT + 1)) - 1;
        while(l != r){
            long long mid = (l + r + 1) / 2;
            if(countOneBits(mid) <= maxOneBits){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }

    long long fastPow(long long a, long long n, long long mod){
        a %= mod;
        long long res = 1 % mod;
        while(n > 0){
            if(n & 1){
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            n >>= 1;
        }
        return res;
    }

public:
    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        const int Q = queries.size();

        vector<int> res(Q);
        for(int qIdx = 0; qIdx < Q; ++qIdx){
            long long from = queries[qIdx][0] + 1;
            long long to = queries[qIdx][1] + 1;
            long long mod = queries[qIdx][2];

            long long a = binarySearchMaxValidNum(from - 1) + 1;
            long long b = binarySearchMaxValidNum(to);
            long long p = 1 % mod;

            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if(a <= b){
                    p *= fastPow(1LL << bit, countOneBits(b, bit) - countOneBits(a, bit), mod);
                    p %= mod;
                }
            }

            int removed = 0;
            for(int bit = MAX_BIT; bit >= 0 && a <= b && countOneBits(a) - removed >= from; --bit){
                if((a >> bit) & 1){
                    p *= fastPow(1LL << bit, 1, mod);
                    p %= mod;
                    removed += 1;
                }
            }

            int added = 0;
            for(int bit = 0; bit <= MAX_BIT && countOneBits(b) + added < to; ++bit){
                if(((b + 1) >> bit) & 1){
                    if(from <= countOneBits(b) + added + 1){
                        p *= fastPow(1LL << bit, 1, mod);
                        p %= mod;
                    }
                    added += 1;
                }
            }

            res[qIdx] = p;
        }

        return res;
    }
};