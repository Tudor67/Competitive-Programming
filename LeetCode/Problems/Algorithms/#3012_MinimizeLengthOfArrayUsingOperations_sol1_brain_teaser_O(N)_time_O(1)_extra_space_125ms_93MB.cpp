class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int minNumCount = count(nums.begin(), nums.end(), minNum);

        for(int num: nums){
            if(num % minNum != 0){
                return 1;
            }
        }

        return (minNumCount + 1) / 2;
    }
};