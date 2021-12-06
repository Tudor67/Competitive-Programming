class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        const int N = nums.size();
        
        int pairsCount = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(i != j && nums[i] + nums[j] == target){
                    pairsCount += 1;
                }
            }
        }
        
        return pairsCount;
    }
};