class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int N = nums.size();
        const int SHIFT = N + 1;
        
        for(int i = 0; i < N; ++i){
            int idx = (nums[i] - 1) % SHIFT;
            nums[idx] %= SHIFT;
            nums[idx] += SHIFT;
        }
        
        vector<int> answer;
        for(int i = 0; i < N; ++i){
            if(nums[i] > SHIFT){
                nums[i] -= SHIFT;
            }else{
                answer.push_back(i + 1);
            }
        }
        
        return answer;
    }
};