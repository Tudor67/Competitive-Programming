class Solution {
private:
    bool isPeak(const vector<int>& NUMS, int idx){
        if(idx == 0){
            return (NUMS.size() == 1 || NUMS[idx] > NUMS[idx + 1]);
        }
        if(idx + 1 == NUMS.size()){
            return (NUMS[idx - 1] < NUMS[idx]);
        }
        return (NUMS[idx - 1] < NUMS[idx] && NUMS[idx] > NUMS[idx + 1]);
    }
    
    int getAnyPeak(const vector<int>& NUMS, const vector<int>& INDICES){
        for(int idx: INDICES){
            if(isPeak(NUMS, idx)){
                return idx;
            }
        }
        return -1;
    }
    
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = (int)nums.size() - 1;
        while(r - l + 1 > 2){
            int mid = (l + r) / 2;
            if(nums[mid - 1] > nums[mid]){
                r = mid;
            }else{
                l = mid;
            }
        }
        return getAnyPeak(nums, {l, r});
    }
};