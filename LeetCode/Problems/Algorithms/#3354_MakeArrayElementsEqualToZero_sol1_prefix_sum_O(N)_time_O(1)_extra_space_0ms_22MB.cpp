class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        const int N = nums.size();
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);

        int res = 0;
        int prefSum = 0;
        int suffSum = TOTAL_SUM;

        for(int i = 0; i < N; ++i){
            prefSum += nums[i];
            suffSum -= nums[i];
            if(nums[i] == 0){
                if(prefSum == suffSum){
                    res += 2;
                }else if(abs(prefSum - suffSum) == 1){
                    res += 1;
                }
            }
        }

        return res;
    }
};