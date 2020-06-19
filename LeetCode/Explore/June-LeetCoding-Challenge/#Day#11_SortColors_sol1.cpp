class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3);
        for(int num: nums){
            ++cnt[num];
        }
        
        int num = 0;
        for(int i = 0; i < nums.size(); ++i){
            while(cnt[num] == 0){
                ++num;
            }
            nums[i] = num;
            --cnt[num];
        }
    }
};