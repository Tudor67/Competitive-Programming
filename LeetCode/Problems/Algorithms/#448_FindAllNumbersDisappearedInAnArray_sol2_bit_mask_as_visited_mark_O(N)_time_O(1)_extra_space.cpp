class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int N = nums.size();
        const int VIS_MASK = 1 << 20;
        
        for(int i = 0; i < N; ++i){
            int idx = (nums[i] & (VIS_MASK - 1)) - 1;
            nums[idx] |= VIS_MASK;
        }
        
        vector<int> answer;
        for(int i = 0; i < N; ++i){
            if(nums[i] & VIS_MASK){
                nums[i] &= (VIS_MASK - 1);
            }else{
                answer.push_back(i + 1);
            }
        }
        
        return answer;
    }
};