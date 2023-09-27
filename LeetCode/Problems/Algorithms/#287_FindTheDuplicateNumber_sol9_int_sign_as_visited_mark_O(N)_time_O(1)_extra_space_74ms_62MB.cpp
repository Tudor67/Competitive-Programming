class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int N = nums.size();

        int duplicate = -1;
        for(int i = 0; i < N && duplicate == -1; ++i){
            int pos = abs(nums[i]) - 1;
            if(nums[pos] < 0){
                duplicate = abs(nums[i]);
            }else{
                nums[pos] = -nums[pos];
            }
        }

        for(int i = 0; i < N; ++i){
            if(nums[i] < 0){
                nums[i] = -nums[i];
            }
        }

        return duplicate;
    }
};