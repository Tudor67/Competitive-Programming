class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end()) + 2;
        
        vector<bool> isPrime(MAX_NUM + 1, true);
        vector<int> primes;
        for(int i = 2; i <= MAX_NUM; ++i){
            if(isPrime[i]){
                primes.push_back(i);
                for(int j = i + i; j <= MAX_NUM; j += i){
                    isPrime[j] = false;
                }
            }
        }
        
        int prevNum = 0;
        for(int num: nums){
            int diff = num - prevNum;
            if(diff <= 0){
                return false;
            }else if(diff == 1 || diff == 2){
                prevNum = num;
            }else{
                int j = lower_bound(primes.begin(), primes.end(), diff) - primes.begin();
                num -= primes[j - 1];
                prevNum = num;
            }
        }
        
        return true;
    }
};