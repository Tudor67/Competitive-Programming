class Solution {
private:
    int countLessThanOrEqual(vector<int>& nums, int threshold){
        int count = 0;
        for(int num: nums){
            if(num <= threshold){
                count += 1;
            }
        }
        return count;
    }

public:
    int findDuplicate(vector<int>& nums) {
        const int N = (int)nums.size() - 1;

        int l = 1;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(countLessThanOrEqual(nums, mid) <= mid){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r;
    }
};