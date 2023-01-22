class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<bool> vis(MAX_NUM + 1, false);

        for(int num: nums){
            for(int i = 2; i * i <= num; ++i){
                while(num % i == 0){
                    num /= i;
                    vis[i] = true;
                }
            }
            if(num > 1){
                vis[num] = true;
            }
        }

        return count(vis.begin(), vis.end(), true);
    }
};