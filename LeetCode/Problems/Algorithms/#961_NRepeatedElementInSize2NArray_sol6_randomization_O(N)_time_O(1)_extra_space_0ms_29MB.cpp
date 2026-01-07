class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        srand(time(nullptr));

        int index = 0;
        do{
            index = rand() % nums.size();
        }while(count(nums.begin(), nums.end(), nums[index]) == 1);
        
        return nums[index];
    }
};