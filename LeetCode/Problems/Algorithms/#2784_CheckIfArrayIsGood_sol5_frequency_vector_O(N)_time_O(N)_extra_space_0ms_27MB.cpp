class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int SIZE = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        if(MAX_NUM + 1 != SIZE){
            return false;
        }

        vector<int> count(MAX_NUM + 1);
        for(int num: nums){
            count[num] += 1;
        }

        for(int num = 1; num <= MAX_NUM - 1; ++num){
            if(count[num] != 1){
                return false;
            }
        }

        return (count[MAX_NUM] == 2);
    }
};