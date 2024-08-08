class Solution {
private:
    bool isIncremovable(vector<int>& nums, int l, int r,
                        int incPrefixEnd, int incSuffixStart){
        const int N = nums.size();
        
        if(incPrefixEnd < l - 1){
            return false;
        }

        if(r + 1 < incSuffixStart){
            return false;
        }

        if(l - 1 >= 0 && r + 1 < N && nums[l - 1] >= nums[r + 1]){
            return false;
        }

        return true;
    }
    
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        const int N = nums.size();

        int incPrefixEnd = 0;
        while(incPrefixEnd + 1 < N && nums[incPrefixEnd] < nums[incPrefixEnd + 1]){
            incPrefixEnd += 1;
        }

        int incSuffixStart = N - 1;
        while(0 <= incSuffixStart - 1 && nums[incSuffixStart - 1] < nums[incSuffixStart]){
            incSuffixStart -= 1;
        }

        long long res = 0;
        int r = 0;
        for(int l = 0; l < N; ++l){
            r = max(r, l);
            while(r < N && !isIncremovable(nums, l, r, incPrefixEnd, incSuffixStart)){
                r += 1;
            }
            res += (N - r);
        }

        return res;
    }
};