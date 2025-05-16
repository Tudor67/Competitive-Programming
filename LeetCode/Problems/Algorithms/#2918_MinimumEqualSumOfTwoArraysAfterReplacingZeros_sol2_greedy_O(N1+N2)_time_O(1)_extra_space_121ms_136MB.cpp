class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        long long sum1 = 0;
        int zeros1 = 0;
        for(int num1: nums1){
            if(num1 == 0){
                zeros1 += 1;
            }else{
                sum1 += num1;
            }
        }

        long long sum2 = 0;
        int zeros2 = 0;
        for(int num2: nums2){
            if(num2 == 0){
                zeros2 += 1;
            }else{
                sum2 += num2;
            }
        }

        long long minValidSum = max(sum1 + zeros1, sum2 + zeros2);
        if((sum1 != minValidSum && zeros1 == 0) ||
           (sum2 != minValidSum && zeros2 == 0)){
            minValidSum = -1;
        }

        return minValidSum;
    }
};