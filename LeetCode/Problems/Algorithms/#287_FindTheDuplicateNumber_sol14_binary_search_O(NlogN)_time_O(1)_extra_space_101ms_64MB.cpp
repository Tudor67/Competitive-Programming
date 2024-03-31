class Solution {
private:
    int countLessOrEqual(vector<int>& nums, int threshold){
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
        const int N = nums.size() - 1;

        int l = 1;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(countLessOrEqual(nums, mid) <= mid){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r;
    }
};