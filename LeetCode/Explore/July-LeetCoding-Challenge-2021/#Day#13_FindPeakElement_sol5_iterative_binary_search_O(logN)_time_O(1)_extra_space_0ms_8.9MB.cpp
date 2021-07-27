class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int N = nums.size();
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid] < nums[mid + 1]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
};