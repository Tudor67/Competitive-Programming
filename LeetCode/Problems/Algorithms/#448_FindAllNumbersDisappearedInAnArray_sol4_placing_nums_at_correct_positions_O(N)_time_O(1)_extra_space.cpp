class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int N = nums.size();
        
        for(int i = 0; i < N; ++i){
            while(nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        vector<int> answer;
        for(int i = 0; i < N; ++i){
            if(nums[i] != i + 1){
                answer.push_back(i + 1);
            }
        }
        
        return answer;
    }
};