class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int newElements = 0;
        int i = 0;
        unsigned int maxSum = 0;
        while(maxSum < n){
            if(i < (int)nums.size() && nums[i] <= maxSum + 1){
                maxSum += nums[i];
                i += 1;
            }else{
                maxSum += (maxSum + 1);
                newElements += 1;
            }
        }
        return newElements;
    }
};