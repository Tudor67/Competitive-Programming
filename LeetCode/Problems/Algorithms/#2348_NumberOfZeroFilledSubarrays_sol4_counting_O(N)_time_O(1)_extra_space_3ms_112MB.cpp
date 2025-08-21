class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int consZeros = 0;
        for(int num: nums){
            if(num == 0){
                consZeros += 1;
                res += consZeros;
            }else{
                consZeros = 0;
            }
        }
        return res;
    }
};