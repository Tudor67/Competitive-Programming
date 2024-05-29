class Solution {
private:
    int countGreaterOrEqual(vector<int>& nums, int threshold){
        int c = 0;
        for(int num: nums){
            if(num >= threshold){
                c += 1;
            }
        }
        return c;
    }

public:
    int specialArray(vector<int>& nums) {
        const int N = nums.size();

        int l = 0;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(mid < countGreaterOrEqual(nums, mid)){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        if(countGreaterOrEqual(nums, r) == r){
            return r;
        }

        return -1;
    }
};