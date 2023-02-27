class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        const int N = nums.size();
        
        long long res = 0;
        for(int i = 0, j = N - 1; i <= j; ++i, --j){
            int pow10 = 1;
            for(int x = nums[j]; x > 0; x /= 10){
                pow10 *= 10;
            }

            if(i == j){
                res += nums[i];
            }else{
                res += nums[i] * pow10 + nums[j];
            }
        }
        
        return res;
    }
};