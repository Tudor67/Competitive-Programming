class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        
        vector<int> primes;
        vector<bool> isPrime(MAX_NUM + 1, true);
        for(int i = 2; i <= MAX_NUM; ++i){
            if(isPrime[i]){
                primes.push_back(i);
                for(int j = i + i; j <= MAX_NUM; j += i){
                    isPrime[j] = false;
                }
            }
        }
        
        vector<int> primeMaskFor(MAX_NUM + 1);
        for(int num = 1; num <= MAX_NUM; ++num){
            for(int j = 0; j < (int)primes.size() && primes[j] <= num; ++j){
                if(num % primes[j] == 0){
                    if((num / primes[j]) % primes[j] == 0){
                        primeMaskFor[num] = 0;
                        break;
                    }else{
                        primeMaskFor[num] |= (1 << j);
                    }
                }
            }
        }
        
        const int P = primes.size();
        const int FULL_MASK = (1 << P) - 1;
        
        // count[mask]: number of elements in vector `nums` with prime factorization
        //              primes[bit[i_1]] * primes[bit[i_2]] * ... * primes[bit[i_k]]
        //              where bit[i_1], bit[i_2], ...,  bit[i_k] represent 1-bits of mask
        vector<long long> count(FULL_MASK + 1);
        int onesCount = 0;
        for(int num: nums){
            if(num == 1){
                onesCount += 1;
            }else if(primeMaskFor[num] > 0){
                count[primeMaskFor[num]] += 1;
            }
        }
        
        // dp[mask]: number of good subsets with product of elements equal to
        //           primes[bit[i_1]] * primes[bit[i_2]] * ... * primes[bit[i_k]]
        //           where bit[i_1], bit[i_2], ...,  bit[i_k] represent 1-bits of mask
        vector<long long> dp(FULL_MASK + 1);
        for(int num = 2; num <= MAX_NUM; ++num){
            int mask = primeMaskFor[num];
            if(count[mask] == 0){
                continue;
            }
            int complMask = mask ^ FULL_MASK;
            for(int complSubmask = complMask; complSubmask > 0; complSubmask = (complSubmask - 1) & complMask){
                dp[complSubmask | mask] += (dp[complSubmask] * count[mask]) % MODULO;
                dp[complSubmask | mask] %= MODULO;
            }
            dp[mask] += count[mask];
        }
        
        long long answer = 0;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            answer += dp[mask];
            answer %= MODULO;
        }
        
        for(int i = 1; i <= onesCount; ++i){
            answer *= 2;
            answer %= MODULO;
        }
        
        return answer;
    }
};