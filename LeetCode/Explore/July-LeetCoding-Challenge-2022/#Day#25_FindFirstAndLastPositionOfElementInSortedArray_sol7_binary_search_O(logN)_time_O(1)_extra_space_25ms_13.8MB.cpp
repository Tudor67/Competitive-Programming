class Solution {
private:
    int lowerBound(vector<int>& nums, int target){
        int l = 0;
        int r = (int)nums.size();
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
    
    int upperBound(vector<int>& nums, int target){
        int l = 0;
        int r = (int)nums.size();
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid] <= target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int N = nums.size();
        
        int firstPos = lowerBound(nums, target);
        int lastPos = upperBound(nums, target) - 1;
        
        if(firstPos == N || nums[firstPos] != target){
            firstPos = -1;
            lastPos = -1;
        }
        
        return {firstPos, lastPos};
    }
};