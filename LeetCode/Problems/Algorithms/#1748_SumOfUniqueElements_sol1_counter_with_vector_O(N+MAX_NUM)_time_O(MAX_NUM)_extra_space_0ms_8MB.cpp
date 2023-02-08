class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> count(MAX_NUM + 1);
        for(int num: nums){
            count[num] += 1;
        }

        int sum = 0;
        for(int num = 0; num <= MAX_NUM; ++num){
            if(count[num] == 1){
                sum += num;
            }
        }

        return sum;
    }
};