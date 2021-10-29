class Solution {
private:
    int findMin(vector<int>& nums, int l, int r){
        if(r - l + 1 <= 2){
            return min(nums[l], nums[r]);
        }
        int mid = (l + r) / 2;
        if(nums[l] < nums[r]){
            return nums[l];
        }
        if(nums[mid] < nums[r]){
            return findMin(nums, l + 1, mid);
        }
        if(nums[mid] > nums[r]){
            return findMin(nums, mid + 1, r);
        }
        // only when nums[l] == nums[mid] == nums[r]
        //           [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
        //           [1,1,0,1,1,1,1,1,1,1,1,1,1,1,1]
        //           [1,1,1,1,1,1,1,1,1,1,1,1,0,1,1]
        return findMin(nums, l + 1, r);
    }
    
public:
    int findMin(vector<int>& nums) {
        const int N = nums.size();
        return findMin(nums, 0, N - 1);
    }
};