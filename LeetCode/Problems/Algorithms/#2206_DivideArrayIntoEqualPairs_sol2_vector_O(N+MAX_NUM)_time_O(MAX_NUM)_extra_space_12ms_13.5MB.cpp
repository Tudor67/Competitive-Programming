class Solution {
public:
    bool divideArray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        vector<int> count(MAX_NUM + 1);
        for(int num: nums){
            count[num] += 1;
        }
        
        for(int num = 0; num <= MAX_NUM; ++num){
            if(count[num] % 2 == 1){
                return false;
            }
        }
        
        return true;
    }
};