class Solution {
private:
    long long valAt(vector<long long>& v, int idx){
        if(0 <= idx && idx < (int)v.size()){
            return v[idx];
        }
        return 0;
    }
    
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        const int MODULO = 1e9 + 7;
        
        vector<long long> dp1(N1);
        vector<long long> dp2(N2);
        
        int i1 = 0;
        int i2 = 0;
        while(i1 < N1 || i2 < N2){
            if(i2 == N2 || (i1 < N1 && nums1[i1] < nums2[i2])){
                dp1[i1] = nums1[i1] + valAt(dp1, i1 - 1);
                i1 += 1;
            }else if(i1 == N1 || nums1[i1] > nums2[i2]){
                dp2[i2] = nums2[i2] + valAt(dp2, i2 - 1);
                i2 += 1;
            }else{
                long long maxPrevDP = max(valAt(dp1, i1 - 1), valAt(dp2, i2 - 1));
                dp1[i1] = nums1[i1] + maxPrevDP;
                dp2[i2] = nums2[i2] + maxPrevDP;
                i1 += 1;
                i2 += 1;
            }
        }
        
        return max(dp1[N1 - 1], dp2[N2 - 1]) % MODULO;
    }
};