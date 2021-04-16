class Solution {
private:
    int minSubarrays(vector<int>& nums, const int& MAX_SUM){
        int sum = 0;
        int subarrays = 1;
        for(int num: nums){
            sum += num;
            if(sum > MAX_SUM){
                sum = num;
                subarrays += 1;
            }
        }
        return subarrays;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        while(l != r){
            int mid = (l + r) / 2;
            if(minSubarrays(nums, mid) <= m){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};