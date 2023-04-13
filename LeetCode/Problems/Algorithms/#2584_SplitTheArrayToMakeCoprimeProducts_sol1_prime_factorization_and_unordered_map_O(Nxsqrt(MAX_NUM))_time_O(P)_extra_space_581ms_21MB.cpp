class Solution {
private:
    void collectPrimeFactors(int num, vector<int>& primeFactors){
        primeFactors.clear();
        for(int i = 2; i * i <= num; ++i){
            if(num % i == 0){
                while(num % i == 0){
                    num /= i;
                }
                primeFactors.push_back(i);
            }
        }
        if(num > 1){
            primeFactors.push_back(num);
        }
    }

public:
    int findValidSplit(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_map<int, int> maxIndexOf;
        vector<int> primeFactors;
        for(int i = 0; i < N; ++i){
            collectPrimeFactors(nums[i], primeFactors);

            for(int primeFactor: primeFactors){
                maxIndexOf[primeFactor] = i;
            }
        }

        int prefMaxIndex = 0;
        for(int i = 0; i + 1 < N; ++i){
            collectPrimeFactors(nums[i], primeFactors);

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
/*
- An index i is valid when (pref = nums[0] * nums[1] * ... * nums[i]) and (suff = nums[i + 1] * ... * nums[N - 1])
  do not share any prime factors;
- Algorithm:
  - Step 1: compute the prime factorization of each num;
            store the max index (in input vector nums) of each prime factor;
  - Step 2: if the max index of any prime factor of (pref = nums[0] * nums[1] * ... * nums[i])
            is equal to i then index i is a valid index;
            why?
            because prime factors of pref are present only in pref => pref and suff don't share any prime factors;
  - Step 3: return the smallest valid index i that satisfies the condition from step 2
                   or -1 otherwise
*/