class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        int index2 = 0;
        for(int num1: nums1){
            while(index2 < N2 && nums2[index2] < num1){
                index2 += 1;
            }
            if(index2 < N2 && nums2[index2] == num1){
                return num1;
            }
        }

        return -1;
    }
};