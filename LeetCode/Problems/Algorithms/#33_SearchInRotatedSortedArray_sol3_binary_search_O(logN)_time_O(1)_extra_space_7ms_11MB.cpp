class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int N = nums.size();

        // Step 1: binary search the index of max num
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

        int maxNumIndex = r;

        // Step 2: binary search the target using the index of max num
        l = maxNumIndex + 1;
        r = maxNumIndex + N;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid % N] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        if(nums[r % N] == target){
            return r % N;
        }
        
        return -1;
    }
};