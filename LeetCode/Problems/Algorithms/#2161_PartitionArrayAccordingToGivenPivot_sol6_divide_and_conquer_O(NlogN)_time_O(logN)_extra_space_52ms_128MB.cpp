class Solution {
private:
    int getIndexOfFirstGreaterNum(const int L, const int R, vector<int>& nums, const int THRESHOLD){
        for(int i = L; i <= R; ++i){
            if(nums[i] > THRESHOLD){
                return i;
            }
        }
        return R + 1;
    }

    void stablePartition(const int L, const int R, vector<int>& nums, const int PIVOT){
        if(R - L + 1 <= 1){
            return;
        }
        
        const int MID = (L + R) / 2;
        stablePartition(L, MID, nums, PIVOT);
        stablePartition(MID + 1, R, nums, PIVOT);

        int firstIndex = getIndexOfFirstGreaterNum(L, MID, nums, PIVOT - 1);
        int secondIndex = getIndexOfFirstGreaterNum(MID + 1, R, nums, PIVOT) - 1;

        reverse(nums.begin() + firstIndex, nums.begin() + MID + 1);
        reverse(nums.begin() + MID + 1, nums.begin() + secondIndex + 1);
        reverse(nums.begin() + firstIndex, nums.begin() + secondIndex + 1);
    }

public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        const int N = nums.size();
        stablePartition(0, N - 1, nums, pivot);
        return nums;
    }
};