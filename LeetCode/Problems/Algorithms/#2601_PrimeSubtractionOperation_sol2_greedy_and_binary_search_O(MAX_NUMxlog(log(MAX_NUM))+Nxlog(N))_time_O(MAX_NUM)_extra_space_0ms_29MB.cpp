class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> primes;
        vector<bool> isPrime(MAX_NUM + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= MAX_NUM; ++i){
            if(isPrime[i]){
                primes.push_back(i);
                for(int j = i + i; j <= MAX_NUM; j += i){
                    isPrime[j] = false;
                }
            }
        }

        int nextNum = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            if(nums[i] < nextNum){
                nextNum = nums[i];
            }else{
                vector<int>::iterator it = upper_bound(primes.begin(), primes.end(), nums[i] - nextNum);
                if(it == primes.end() || nums[i] <= *it){
                    return false;
                }else{
                    nextNum = nums[i] - *it;
                }
            }
        }

        return true;
    }
};