class Solution {
private:
    bool isPossible(vector<int>& nums, long long threshold){
        const int N = nums.size();
        long long excess = 0;
        for(int i = N - 1; i >= 0; --i){
            long long newNum = nums[i] + excess;
            excess = max(0LL, newNum - threshold);
        }
        return (excess == 0);
    }

public:
    int minimizeArrayValue(vector<int>& nums) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        int l = MIN_NUM;
        int r = MAX_NUM;
        while(l != r){
            int mid = (l + r) / 2;
            if(isPossible(nums, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return r;
    }
};