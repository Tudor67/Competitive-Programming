class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        
        int firstPos = 0;
        int secondPos = 1;
        if(nums[firstPos] < nums[secondPos]){
            swap(firstPos, secondPos);
        }
        
        for(int i = 2; i < N; ++i){
            if(nums[i] > nums[firstPos]){
                secondPos = firstPos;
                firstPos = i;
            }else if(nums[i] > nums[secondPos]){
                secondPos = i;
            }
            // nums[firstPos] and nums[secondPos]: the largest two values from nums[0 .. i]
            // such that nums[firstPos] >= nums[secondPos]
        }
        
        return (nums[firstPos] - 1) * (nums[secondPos] - 1);
    }
};