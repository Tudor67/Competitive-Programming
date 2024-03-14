class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        int i1 = 0;
        int i2 = 0;
        while(i1 < N1 && i2 < N2){
            if(nums1[i1] < nums2[i2]){
                i1 += 1;
            }else if(nums1[i1] > nums2[i2]){
                i2 += 1;
            }else{
                return nums1[i1];
            }
        }

        return -1;
    }
};