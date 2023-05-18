class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int res = INT_MAX;

        for(int num1: nums1){
            for(int num2: nums2){
                if(num1 == num2){
                    res = min(res, num1);
                }else{
                    res = min(res, min(num1 * 10 + num2, num2 * 10 + num1));
                }
            }
        }
        
        return res;
    }
};