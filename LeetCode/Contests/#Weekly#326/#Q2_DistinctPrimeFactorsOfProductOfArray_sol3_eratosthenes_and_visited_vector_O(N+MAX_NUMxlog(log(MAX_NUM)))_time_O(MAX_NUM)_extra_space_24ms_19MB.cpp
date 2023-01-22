class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<bool> vis(MAX_NUM + 1, false);
        for(int num: nums){
            vis[num] = true;
        }

        int res = 0;
        vector<bool> isPrime(MAX_NUM + 1, true);
        for(int i = 2; i <= MAX_NUM; ++i){
            if(isPrime[i]){
                bool matches = vis[i];
                for(int j = i + i; j <= MAX_NUM; j += i){
                    isPrime[j] = false;
                    matches = matches || vis[j];
                }
                if(matches){
                    res += 1;
                }
            }
        }

        return res;
    }
};