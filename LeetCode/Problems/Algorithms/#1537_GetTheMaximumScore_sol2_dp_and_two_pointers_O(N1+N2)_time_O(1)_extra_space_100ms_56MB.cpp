class Solution {    
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        const int MODULO = 1e9 + 7;
        
        vector<long long> dp1(2);
        vector<long long> dp2(2);
        
        int i1 = 0;
        int i2 = 0;
        while(i1 < N1 || i2 < N2){
            if(i2 == N2 || (i1 < N1 && nums1[i1] < nums2[i2])){
                dp1[i1 % 2] = nums1[i1] + dp1[(i1 + 1) % 2];
                i1 += 1;
            }else if(i1 == N1 || nums1[i1] > nums2[i2]){
                dp2[i2 % 2] = nums2[i2] + dp2[(i2 + 1) % 2];
                i2 += 1;
            }else{
                long long maxPrevDP = max(dp1[(i1 + 1) % 2], dp2[(i2 + 1) % 2]);
                dp1[i1 % 2] = nums1[i1] + maxPrevDP;
                dp2[i2 % 2] = nums2[i2] + maxPrevDP;
                i1 += 1;
                i2 += 1;
            }
        }
        
        return max(dp1[(N1 - 1) % 2], dp2[(N2 - 1) % 2]) % MODULO;
    }
};