class Solution {
public:
    int countPrimes(int N) {
        N -= 1;
        if(N <= 1){
            return 0;
        }
        
        const int SQRT_N = sqrt(N);
        vector<bool> isPrime(SQRT_N + 1, true);
        
        vector<int> sqrtPrimes; // all primes from the range [2 .. SQRT_N]
        for(int i = 2; i <= SQRT_N; ++i){
            if(isPrime[i]){
                sqrtPrimes.push_back(i);
                for(int j = i * i; j <= SQRT_N; j += i){
                    isPrime[j] = false;
                }
            }
        }
        
        const int BLOCK_SIZE = SQRT_N;
        const int BLOCKS_COUNT = N / BLOCK_SIZE + 1;
        isPrime.resize(BLOCK_SIZE);
        
        int primesCount = 0;
        for(int blockIdx = 0; blockIdx <= BLOCKS_COUNT - 1; ++blockIdx){
            // block range: [startNum, endNum]
            int startNum = blockIdx * BLOCK_SIZE;
            int endNum = min(N, startNum + BLOCK_SIZE - 1);
            fill(isPrime.begin(), isPrime.end(), true);
            for(int p: sqrtPrimes){
                int firstCompositeNumOfBlock = max((startNum + p - 1) / p, p) * p;
                for(int c = firstCompositeNumOfBlock; c <= endNum; c += p){
                    isPrime[c - startNum] = false;
                }
            }
            for(int num = max(2, startNum); num <= endNum; ++num){
                primesCount += isPrime[num - startNum];
            }
        }
        
        return primesCount;
    }
};