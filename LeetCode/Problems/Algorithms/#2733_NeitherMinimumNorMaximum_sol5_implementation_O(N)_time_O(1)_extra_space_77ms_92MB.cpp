class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        for(int num: nums){
            if(num != MIN_NUM && num != MAX_NUM){
                return num;
            }
        }

        return -1;
    }
};