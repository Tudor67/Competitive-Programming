class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int N = nums.size();

        vector<int> freq(3);
        for(int num: nums){
            freq[num] += 1;
        }

        int i = 0;
        for(int num = 0; num < (int)freq.size(); ++num){
            for(int f = 1; f <= freq[num]; ++f){
                nums[i] = num;
                i += 1;
            }
        }
    }
};