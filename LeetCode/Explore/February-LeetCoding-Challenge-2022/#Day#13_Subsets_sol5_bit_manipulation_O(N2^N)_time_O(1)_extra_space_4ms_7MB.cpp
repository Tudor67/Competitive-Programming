class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int N = nums.size();
        const int FULL_MASK = (1 << N) - 1;
        
        vector<vector<int>> answer(FULL_MASK + 1);
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    answer[mask].push_back(nums[bit]);
                }
            }
        }
        
        return answer;
    }
};