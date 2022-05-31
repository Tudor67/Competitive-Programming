class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }
        
        int res = 0;
        for(int num: nums){
            if(count[num] >= 1){
                count[num] -= 1;
                if(count.count(k - num) && count[k - num] >= 1){
                    count[k - num] -= 1;
                    res += 1;
                }
            }
        }
        
        return res;
    }
};