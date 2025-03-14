class Solution {
private:
    int lowerBound(vector<int>& nums, int threshold){
        int l = 0;
        int r = nums.size();
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid] < threshold){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

public:
    int maximumCount(vector<int>& nums) {
        int negative = lowerBound(nums, 0);
        int positive = (int)nums.size() - lowerBound(nums, 1);
        return max(negative, positive);
    }
};