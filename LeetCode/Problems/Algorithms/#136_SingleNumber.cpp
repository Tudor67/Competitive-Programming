class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int elem: nums){
            ans ^= elem;
        }
        return ans;
    }
};