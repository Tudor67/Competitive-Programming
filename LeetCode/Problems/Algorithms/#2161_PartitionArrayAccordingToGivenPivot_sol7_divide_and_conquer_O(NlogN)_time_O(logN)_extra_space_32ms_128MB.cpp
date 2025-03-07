class Solution {
private:
    void stablePartition(const int L, const int R, vector<int>& nums, const int PIVOT){
        if(R - L + 1 <= 1){
            return;
        }
        
        const int MID = (L + R) / 2;
        stablePartition(L, MID, nums, PIVOT);
        stablePartition(MID + 1, R, nums, PIVOT);

        int firstIndex = lower_bound(nums.begin() + L, nums.begin() + MID + 1, PIVOT) - nums.begin();
        int secondIndex = upper_bound(nums.begin() + MID + 1, nums.begin() + R + 1, PIVOT) - nums.begin();

        rotate(nums.begin() + firstIndex, nums.begin() + MID + 1, nums.begin() + secondIndex);
    }

public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        const int N = nums.size();
        stablePartition(0, N - 1, nums, pivot);
        return nums;
    }
};