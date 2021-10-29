class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        for(int num: nums){
            ++count[num];
        }
        
        int i = -1;
        for(int num = 0; num <= 2; ++num){
            for(int j = 0; j < count[num]; ++j){
                nums[++i] = num;
            }
        }
    }
};