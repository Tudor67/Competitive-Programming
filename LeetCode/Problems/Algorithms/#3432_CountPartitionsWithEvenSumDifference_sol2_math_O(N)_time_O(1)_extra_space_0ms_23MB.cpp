class Solution {
public:
    int countPartitions(vector<int>& nums) {
        const int N = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum % 2 == 0){
            return N - 1;
        }

        return 0;
    }
};