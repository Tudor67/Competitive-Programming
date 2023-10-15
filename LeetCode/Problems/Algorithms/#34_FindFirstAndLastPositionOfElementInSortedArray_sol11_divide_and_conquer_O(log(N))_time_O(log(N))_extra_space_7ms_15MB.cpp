class Solution {
private:
    vector<int> search(vector<int>& nums, int l, int r, int target){
        if(target < nums[l] || nums[r] < target){
            return {-1, -1};
        }

        if(target == nums[l] && nums[r] == target){
            return {l, r};
        }

        int mid = (l + r) / 2;
        vector<int> leftRes = search(nums, l, mid, target);
        vector<int> rightRes = search(nums, mid + 1, r, target);
        
        if(leftRes[0] == -1){
            return rightRes;
        }
        if(rightRes[0] == -1){
            return leftRes;
        }

        return {leftRes[0], rightRes[1]};
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int N = nums.size();

        if(nums.empty()){
            return {-1, -1};
        }

        return search(nums, 0, N - 1, target);
    }
};