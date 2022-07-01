class Solution {
private:
    int computeRemainder(vector<int>& nums, int minThreshold, int k){
        for(int num: nums){
            if(num < minThreshold){
                k -= (minThreshold - num);
            }
            if(k < 0){
                return -1;
            }
        }
        return k;
    }
    
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MODULO = 1e9 + 7;
        
        int l = MIN_NUM;
        int r = MAX_NUM + k;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(computeRemainder(nums, mid, k) >= 0){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        int minThreshold = r;
        int remainder = computeRemainder(nums, minThreshold, k);
        
        long long p = 1;
        for(int num: nums){
            if(num <= minThreshold){
                num = minThreshold;
                if(remainder >= 1){
                    num += 1;
                    remainder -= 1;
                }
            }
            p *= num;
            p %= MODULO;
        }
        
        return p;
    }
};