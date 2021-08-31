class Solution {
public:
    int findMin(vector<int>& nums) {
        const int N = nums.size();
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(nums[0] < nums[mid]){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return nums[(r + 1) % N];
    }
};