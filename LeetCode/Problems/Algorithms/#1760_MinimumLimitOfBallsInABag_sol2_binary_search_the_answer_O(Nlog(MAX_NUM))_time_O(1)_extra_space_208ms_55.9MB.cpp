class Solution {
private:
    long long getMinOperations(vector<int>& nums, const int& MAX_VALID_NUM){
        long long minOperations = 0;
        for(int num: nums){
            minOperations += (num + MAX_VALID_NUM - 1) / MAX_VALID_NUM - 1;
        }
        return minOperations;
    }
    
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        int l = 1;
        int r = MAX_NUM;
        while(l != r){
            int mid = (l + r) / 2;
            if(getMinOperations(nums, mid) <= maxOperations){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};