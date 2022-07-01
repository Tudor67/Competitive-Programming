class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MODULO = 1e9 + 7;
        
        vector<int> count(MAX_NUM + k + 1);
        for(int num: nums){
            count[num] += 1;
        }
        
        for(int num = 0; num + 1 < (int)count.size() && k > 0; ++num){
            if(count[num] > 0){
                int minCount = min(count[num], k);
                count[num + 1] += minCount;
                k -= minCount;
                count[num] -= minCount;
            }
        }
        
        long long prod = 1;
        for(int num = 0; num < (int)count.size(); ++num){
            while(count[num] > 0){
                prod *= num;
                prod %= MODULO;
                count[num] -= 1;
            }
        }
        
        return prod;
    }
};