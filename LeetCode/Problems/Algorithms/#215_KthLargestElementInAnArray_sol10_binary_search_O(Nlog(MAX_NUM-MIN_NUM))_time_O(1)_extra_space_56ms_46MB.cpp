class Solution {
private:
    int countGreaterThanOrEqual(vector<int>& nums, int threshold){
        int count = 0;
        for(int num: nums){
            if(threshold <= num){
                count += 1;
            }
        }
        return count;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        int l = MIN_NUM;
        int r = MAX_NUM + 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(mid * 2 > l + r){
                mid -= 1;
            }
            if(countGreaterThanOrEqual(nums, mid) >= k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r - 1;
    }
};