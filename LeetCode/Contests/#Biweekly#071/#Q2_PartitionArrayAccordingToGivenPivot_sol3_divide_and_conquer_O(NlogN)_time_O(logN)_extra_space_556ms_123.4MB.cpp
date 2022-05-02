class Solution {
private:
    void stable_partition(vector<int>& nums, const int& L, const int& R, const int& PIVOT){
        if(L >= R){
            return;
        }
        
        int mid = (L + R) / 2;
        stable_partition(nums, L, mid, PIVOT);
        stable_partition(nums, mid + 1, R, PIVOT);
        
        int lower = lower_bound(nums.begin() + L, nums.begin() + mid + 1, PIVOT) - nums.begin();
        int upper = upper_bound(nums.begin() + mid + 1, nums.begin() + R + 1, PIVOT) - nums.begin();
        
        reverse(nums.begin() + lower, nums.begin() + mid + 1);
        reverse(nums.begin() + mid + 1, nums.begin() + upper);
        reverse(nums.begin() + lower, nums.begin() + upper);
    }
    
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        const int N = nums.size();
        stable_partition(nums, 0, N - 1, pivot);
        return nums;
    }
};