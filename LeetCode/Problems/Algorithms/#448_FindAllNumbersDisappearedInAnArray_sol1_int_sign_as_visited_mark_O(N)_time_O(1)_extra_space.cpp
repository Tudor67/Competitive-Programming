class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int N = nums.size();
        for(int i = 0; i < N; ++i){
            int idx = abs(nums[i]) - 1;
            nums[idx] = -abs(nums[idx]);
        }
        
        vector<int> answer;
        for(int i = 0; i < N; ++i){
            if(nums[i] < 0){
                nums[i] = -nums[i];
            }else{
                answer.push_back(i + 1);
            }
        }
        
        return answer;
    }
};