class Solution {    
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        const int MODULO = 1e9 + 7;
        
        long long sum1 = 0;
        long long sum2 = 0;
        
        int i1 = 0;
        int i2 = 0;
        while(i1 < N1 && i2 < N2){
            if(nums1[i1] < nums2[i2]){
                sum1 += nums1[i1];
                i1 += 1;
            }else if(nums1[i1] > nums2[i2]){
                sum2 += nums2[i2];
                i2 += 1;
            }else{
                long long maxSum = max(sum1, sum2);
                sum1 = maxSum + nums1[i1];
                sum2 = maxSum + nums2[i2];
                i1 += 1;
                i2 += 1;
            }
        }
        
        while(i1 < N1){
            sum1 += nums1[i1];
            i1 += 1;
        }
        
        while(i2 < N2){
            sum2 += nums2[i2];
            i2 += 1;
        }
        
        return max(sum1, sum2) % MODULO;
    }
};