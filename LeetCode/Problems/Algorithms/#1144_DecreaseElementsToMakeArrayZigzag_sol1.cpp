class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        const int N = nums.size();
        
        // Case 1: nums[0] < nums[1] > nums[2] < ....        
        int moves1 = 0;
        for(int i = 0; i < N; i += 2){
            int left_num = (i > 0 ? nums[i - 1] : 1e9);
            int right_num = (i < N - 1 ? nums[i + 1] : 1e9);
            int line = min(left_num, right_num);
            if(nums[i] >= line){
                moves1 += (nums[i] - line + 1);
            }
        }
        
        // Case 2: nums[0] > nums[1] < nums[2] > ....
        int moves2 = 0;
        for(int i = 1; i < N; i += 2){
            int left_num = (i > 0 ? nums[i - 1] : 1e9);
            int right_num = (i < N - 1 ? nums[i + 1] : 1e9);
            int line = min(left_num, right_num);
            if(nums[i] >= line){
                moves2 += (nums[i] - line + 1);
            }
        }
        
        return min(moves1, moves2);
    }
};