class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        for(int k = m + n - 1; k >= 0; --k){
            if(j < 0 || (i >= 0 && nums1[i] >= nums2[j])){
                nums1[k] = nums1[i];
                i -= 1;
            }else{
                nums1[k] = nums2[j];
                j -= 1;
            }
        }
    }
};