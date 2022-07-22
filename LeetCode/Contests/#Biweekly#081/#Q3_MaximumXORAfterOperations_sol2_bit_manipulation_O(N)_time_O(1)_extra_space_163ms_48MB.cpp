class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        const int N = nums.size();
        
        int res = 0;
        for(int num: nums){
            res |= num;
        }
        
        return res;
    }
};