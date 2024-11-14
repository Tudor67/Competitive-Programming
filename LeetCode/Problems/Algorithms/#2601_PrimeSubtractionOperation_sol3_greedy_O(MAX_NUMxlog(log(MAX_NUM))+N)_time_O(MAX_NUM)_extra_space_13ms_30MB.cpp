class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int INF = 1e9;

        vector<bool> isPrime(MAX_NUM + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= MAX_NUM; ++i){
            if(isPrime[i]){
                for(int j = i + i; j <= MAX_NUM; j += i){
                    isPrime[j] = false;
                }
            }
        }

        vector<int> nextPrime(MAX_NUM + 2, INF);
        for(int num = MAX_NUM; num >= 0; --num){
            if(isPrime[num]){
                nextPrime[num] = num;
            }else{
                nextPrime[num] = nextPrime[num + 1];
            }
        }

        int nextNum = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            if(nums[i] < nextNum){
                nextNum = nums[i];
            }else{
                int diff = nums[i] - nextNum;
                if(nextPrime[diff + 1] < nums[i]){
                    nextNum = nums[i] - nextPrime[diff + 1];
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};