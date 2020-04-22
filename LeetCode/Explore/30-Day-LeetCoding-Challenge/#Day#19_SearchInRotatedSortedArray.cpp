class Solution {
public:
    int search(vector<int>& nums, int target) {
        int answer = -1;
        
        if(!nums.empty()){
            const int n = nums.size();

            // Step 1: binary search the position of maximum: O(logN)
            int l = 0;
            int r = n - 1;
            while(l != r){
                int mid = (l + r + 1) / 2;
                if(nums[l] < nums[mid]){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            int max_pos = r;

            // Step 2: binary search the target: O(logN)
            l = max_pos + 1;
            r = max_pos + n;
            while(l != r){
                int mid = (l + r + 1) / 2;
                if(nums[mid % n] <= target){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }

            if(nums[r % n] == target){
                answer = r % n;
            }
        }
        
        return answer;
    }
};