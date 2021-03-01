class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int N = nums.size();
        int answer = 0;
        
        // Step 1: find the longest `broken` subarray nums[p1 .. p2],
        //         such that nums[p1] > nums[p1 + 1] and nums[p2 - 1] > nums[p2]
        int p1 = 0;
        while(p1 + 1 < N && nums[p1] <= nums[p1 + 1]){
            p1 += 1;
        }
        
        int p2 = N - 1;
        while(p1 <= p2 - 1 && nums[p2 - 1] <= nums[p2]){
            p2 -= 1;
        }
        
        if(p1 < p2){
            // Step 2.1: find min and max elements of the `broken` subarray nums[p1 .. p2]
            const int MIN_ELEM = *min_element(nums.begin() + p1, nums.begin() + p2 + 1);
            const int MAX_ELEM = *max_element(nums.begin() + p1, nums.begin() + p2 + 1);
            
            // Step 2.2: extend the `broken` subarray nums[p1 .. p2] to the left and to the right
            //           to satisfy the following condition:
            //           nums[p1 - 1] <= MIN_ELEM && MAX_ELEM <= nums[p2 + 1]
            p1 = 0;
            while(p1 < N && nums[p1] <= MIN_ELEM){
                p1 += 1;
            }
            
            p2 = N - 1;
            while(p1 < p2 && MAX_ELEM <= nums[p2]){
                p2 -= 1;
            }
            
            answer = p2 - p1 + 1;
        }
        
        return answer;
    }
};