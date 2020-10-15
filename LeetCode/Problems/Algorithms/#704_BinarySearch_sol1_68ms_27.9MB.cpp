class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = (int)nums.size() - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return (nums[r] == target ? r : -1);
    }
};