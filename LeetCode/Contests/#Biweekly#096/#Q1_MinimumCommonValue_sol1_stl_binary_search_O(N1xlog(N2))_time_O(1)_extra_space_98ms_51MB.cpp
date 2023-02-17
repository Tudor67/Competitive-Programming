class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        for(int num1: nums1){
            if(binary_search(nums2.begin(), nums2.end(), num1)){
                return num1;
            }
        }
        
        return -1;
    }
};