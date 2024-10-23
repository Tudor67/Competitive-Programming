class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations = 0;
        for(int num: nums){
            if(num < k){
                operations += 1;
            }
        }
        return operations;
    }
};