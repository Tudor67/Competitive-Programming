class Solution {
private:
    void collectPrimeFactors(int num, vector<int>& minPrime, vector<int>& primeFactors){
        primeFactors.clear();
        while(num > 1){
            primeFactors.push_back(minPrime[num]);
            num /= minPrime[num];
        }
    }

public:
    int findValidSplit(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> minPrime(MAX_NUM + 2, -1);
        vector<int> primes;
        for(int num = 2; num <= MAX_NUM; ++num){
            if(minPrime[num] == -1){
                minPrime[num] = num;
                primes.push_back(num);
            }
            for(int idx = 0; idx < (int)primes.size() && primes[idx] <= minPrime[num] && primes[idx] * num <= MAX_NUM; ++idx){
                minPrime[primes[idx] * num] = primes[idx];
            }
        }

        vector<int> maxIndexOf(MAX_NUM + 2);
        vector<int> primeFactors;
        for(int i = 0; i < N; ++i){
            collectPrimeFactors(nums[i], minPrime, primeFactors);
            for(int primeFactor: primeFactors){
                maxIndexOf[primeFactor] = i;
            }
        }

        int prefMaxIndex = 0;
        for(int i = 0; i + 1 < N; ++i){
            collectPrimeFactors(nums[i], minPrime, primeFactors);
            for(int primeFactor: primeFactors){
                prefMaxIndex = max(prefMaxIndex, maxIndexOf[primeFactor]);
            }
            if(i == prefMaxIndex){
                return i;
            }
        }

        return -1;
    }
};