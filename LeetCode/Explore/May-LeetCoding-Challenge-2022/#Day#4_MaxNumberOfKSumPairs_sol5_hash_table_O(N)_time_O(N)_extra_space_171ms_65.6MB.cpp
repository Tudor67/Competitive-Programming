class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int res = 0;
        unordered_map<int, int> count;
        for(int num: nums){
            if(count.count(k - num) && count[k - num] >= 1){
                count[k - num] -= 1;
                res += 1;
            }else{
                count[num] += 1;
            }
        }
        
        return res;
    }
};