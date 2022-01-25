class Solution {
public:
    int specialArray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        vector<int> suffCount(MAX_NUM + 1);
        for(int num: nums){
            suffCount[num] += 1;
        }
        
        for(int num = MAX_NUM - 1; num >= 0; --num){
            suffCount[num] += suffCount[num + 1];
        }
        
        int i = 0;
        for(int x = 1; x <= min(N, MAX_NUM); ++x){
            if(x == suffCount[x]){
                return x;
            }
        }
        
        return -1;
    }
};