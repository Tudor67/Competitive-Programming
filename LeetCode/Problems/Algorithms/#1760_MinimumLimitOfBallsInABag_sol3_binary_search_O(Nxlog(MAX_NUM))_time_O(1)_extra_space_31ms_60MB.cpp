class Solution {
private:
    long long computeMinOperations(vector<int>& nums, int threshold){
        long long minOperations = 0;
        for(int num: nums){
            minOperations += (num + threshold - 1) / threshold - 1;
        }
        return minOperations;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while(l != r){
            int mid = (l + r) / 2;
            if(computeMinOperations(nums, mid) <= maxOperations){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};