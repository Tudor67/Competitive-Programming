class Solution {
private:
    int lowerBound(vector<int>& nums, int target){
        const int N = nums.size();

        int l = 0;
        int r = N;
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

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int N = nums.size();

        int firstPos = lowerBound(nums, target);
        int lastPos = lowerBound(nums, target + 1) - 1;

        if(firstPos < N && nums[firstPos] == target){
            return {firstPos, lastPos};
        }

        return {-1, -1};
    }
};