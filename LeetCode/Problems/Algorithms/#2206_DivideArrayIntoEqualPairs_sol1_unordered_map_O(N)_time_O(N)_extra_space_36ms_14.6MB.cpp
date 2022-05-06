class Solution {
public:
    bool divideArray(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }
        
        for(const pair<int, int>& P: count){
            int numCount = P.second;
            if(numCount % 2 == 1){
                return false;
            }
        }
        
        return true;
    }
};