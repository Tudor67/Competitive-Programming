class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        const int N = nums1.size();
        
        // Special case
        if(k == 0){
            if(nums1 == nums2){
                return 0;
            }else{
                return -1;
            }
        }
        
        // Compute inc and dec operations (if possible)
        long long inc = 0;
        long long dec = 0;
        for(int i = 0; i < N; ++i){
            long long diff = nums1[i] - nums2[i];
            if(diff % k == 0){
                if(diff < 0){
                    inc += (-diff / k);
                }else if(diff > 0){
                    dec += (diff / k);
                }
            }else{
                return -1;
            }
        }
        
        // The number of inc and dec operations should be the same
        if(inc != dec){
            return -1;
        }
        
        return inc;
    }
};